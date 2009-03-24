#include "user_map.h"

SDL_Surface *screen;

int** genRandomMap(int rowNum, int colNum);

void sdl_init(){
  SDL_Init( SDL_INIT_EVERYTHING );
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {//turn video on
    printf("Unable to initialize SDL: %s\n", SDL_GetError());
    exit(1);
  }
  atexit(SDL_Quit);
  screen = SDL_SetVideoMode(SCREEN_HEIGHT, SCREEN_WIDTH, 16, SDL_DOUBLEBUF);//video settings
  if (screen == NULL) {
    printf("Unable to set video mode: %s\n", SDL_GetError());
    exit(2);
  }
  SDL_WM_SetCaption( "Tux Bomber", NULL ); 
}

SDL_Surface *load_image( std::string filename )
{
	SDL_RWops *rwop;
	rwop=SDL_RWFromFile(filename.c_str(), "rb");
	
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;
	
	if(IMG_isGIF(rwop))
		loadedImage = IMG_LoadGIF_RW(rwop);
    else
        //Load the image
    	loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}

int main()
{
	int **map;
	
	SDL_Surface *image_set = load_image( "empty.xcf" );;
	int numImages = 3;
	int width = 18;
	int height = 17;
	
	map = genRandomMap(height,width);

	for( int i = 0 , j = -1 ; i < 306; i++)
		{
			if (i %18 == 0 )
			{
				printf("\n");
				j++;
			}
			printf(" %d",map[j][i%18]);
		}
		 
	fflush(stdout);

	user_map *uMap = new user_map(map,image_set,numImages,height,width);

	sdl_init();

	uMap->draw_map(screen);

	
}


