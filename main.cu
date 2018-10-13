#include <iostream>
#include <SDL2/SDL.h>
#include "RenderTarget.h"

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 60;

int main(){

	RenderTarget r;

	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Renderer* renderer = NULL;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
		cerr<<"SDL could not initialize! SDL_Error:  "<< SDL_GetError() << endl;

	else
	{
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );


		if( !window )
			cerr<<"Window could not be created! SDL_Error:  " << SDL_GetError() <<endl;
		else
		{
			screenSurface = SDL_GetWindowSurface( window );
			cout<<screenSurface->pixels<<endl;
			int gap = 17;
			for(int s = 0;s<20000;s+=gap){
				SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, s%255, s%255, s%255 ) );

				SDL_UpdateWindowSurface( window );

				SDL_Delay( gap );
			}

		}
	}

	SDL_DestroyWindow( window );
	SDL_Quit();

	return 0;
}
