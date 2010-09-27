#include <stdio.h>
#include "SDL.h"
#include "game_util.h"

int game_done = 0;
const int MAX_FPS = 60;

enum {
	INTRO,
	MENU,
	LEVEL
};

void run_intro(SDL_Surface* screen);
void run_menu(SDL_Surface* screen);
void run_level(SDL_Surface* screen);

int main(int argc,char** argv) {
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)) {
		fprintf(stderr,"Could not initialize SDL. Exiting.\n");
		return 1;
	}
	SDL_Surface* screen = SDL_SetVideoMode(640,480,32,SDL_SWSURFACE);
	
	run_intro(screen);
	run_menu(screen);
	SDL_Quit();
}

void run_intro(SDL_Surface* screen) {
	
};

void run_menu(SDL_Surface* screen) {
	int frame = 0;
	game_timer* fps_timer = game_timer_new();
	game_timer_start(fps_timer);
	SDL_Event event;
	SDL_Surface* background;
	SDL_Surface* title_card;
	SDL_Surface* selector;
	SDL_Surface* start_game;
	SDL_Surface* quit_game;
	background = load_image("art/menu/background.png");
	title_card = load_image("art/menu/titlecard.png");
	selector   = load_image("art/menu/selector.png");
	start_game = load_image("art/menu/startgame.png");
	quit_game  = load_image("art/menu/quit.png");
	int selector_max = 1;
	int selector_pos = 0;
	int selector_x   = 10;
	int selector_y   = 110;
	int selector_y_mul = 60;
	apply_surface(selector_x,(selector_y + (selector_y_mul * selector_pos)),selector,screen);
	
	while(!game_done) {
		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_KEYDOWN) {
				if(event.key.keysym.sym == SDLK_DOWN) {
					if(selector_pos < selector_max) {
						selector_pos++;
					}
				} else if(event.key.keysym.sym == SDLK_UP) {
					if(selector_pos > 0) {
						selector_pos--;
					}
				} else if(event.key.keysym.sym == SDLK_RETURN) {
					switch(selector_pos) {
						case 0:
						run_level(screen);
						break;
						case 1:
						game_done = 1;
						break;
					}
				}
			} else if(event.type == SDL_QUIT) {
				game_done = 1;
			}
			
			// Redrawing
			apply_surface(0,0,background,screen);
			apply_surface(20,20,title_card,screen);
			apply_surface(40,100,start_game,screen);
			apply_surface(40,160,quit_game,screen);
			apply_surface(selector_x,(selector_y + (selector_y_mul * selector_pos)),selector,screen);
			SDL_Flip(screen);
			frame++;
			
			if(game_timer_get_ticks(fps_timer) < 1000 / MAX_FPS) {
				SDL_Delay((1000 / MAX_FPS) - game_timer_get_ticks(fps_timer));
			}
		}
	}

};

void run_level(SDL_Surface* screen) {
	
};
