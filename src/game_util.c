#include "SDL.h"
#include "SDL_image.h"
#include "game_util.h"

SDL_Surface* load_image(char* filename) {
	SDL_Surface* loaded_image = NULL;
	SDL_Surface* optimized_image = NULL;
	
	loaded_image = IMG_Load(filename);
	if(loaded_image != NULL) {
		optimized_image = SDL_DisplayFormat(loaded_image);
		SDL_FreeSurface(loaded_image);
	}
	return optimized_image;
}

void apply_surface(int x,int y,SDL_Surface* source,SDL_Surface* dest) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(source,NULL,dest,&offset);
}

game_timer* game_timer_new() {
	game_timer* timer = malloc(sizeof(game_timer));
	
	timer->start_ticks  = 0;
	timer->paused_ticks = 0;
	timer->paused       = 0;
	timer->started      = 0;
	
	return timer;
}

void game_timer_start(game_timer* timer) {
	timer->started = 1;
	timer->paused  = 0;
	
	timer->start_ticks = SDL_GetTicks();
}

void game_timer_stop(game_timer* timer) {
	timer->started = 0;
	timer->paused  = 0;
}

int game_timer_get_ticks(game_timer* timer) {
	if(timer->started) {
		if(timer->paused) {
			return timer->paused_ticks;
		} else {
			return SDL_GetTicks() - timer->start_ticks;
		}
	} else {
		return 0;
	}
}

void game_timer_pause(game_timer* timer) {
	if(timer->started && !timer->paused) {
		timer->paused = 1;
		timer->paused_ticks = SDL_GetTicks() - timer->start_ticks;
	}
}

void game_timer_unpause(game_timer* timer) {
	if(timer->paused) {
		timer->paused = 0;
		
		timer->start_ticks = SDL_GetTicks() - timer->paused_ticks;
		
		timer->paused_ticks = 0;
	}
}

int game_timer_is_paused(game_timer* timer) {
	return timer->paused;
}

int game_timer_is_started(game_timer* timer) {
	return timer->started;
}
