#include <stdio.h>
#include "SDL.h"
#include "game_util.h"

enum {
	INTRO,
	MENU,
	LEVEL
}

int main(int argc,char** argv) {
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)) {
		fprintf(stderr,"Could not initialize SDL. Exiting.\n");
		return 1;
	}
	SDL_Surface* screen = SDL_SetVideoMode(640,480,32,SDL_SWSURFACE);
	
	// Starting up
	int game_state = INTRO;
	int quit = 0;
	while(!quit) {
		switch(game_state) {
			case INTRO:
			
			break;
			case MENU;
			
			break;
			case LEVEL;
			
			break;
		}
	}
	SDL_Quit();
}
