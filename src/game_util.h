#include "SDL.h"

SDL_Surface* load_image(char* filename);

void apply_surface(int x,int y,SDL_Surface* source,SDL_Surface* dest);

typedef struct {
	int start_ticks;
	int paused_ticks;
	int paused;
	int started;
} game_timer;

game_timer* game_timer_new(void);
void game_timer_start(game_timer* timer);
void game_timer_stop(game_timer* timer);
void game_timer_pause(game_timer* timer);
void game_timer_unpause(game_timer* timer);
int game_timer_get_ticks(game_timer* timer);
int game_timer_is_started(game_timer* timer);
int game_timer_is_paused(game_timer* timer);
