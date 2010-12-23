#include <stdio.h>
#include "SDL.h"

typedef struct {
	int max_fps;
	int fullscreen;
	int width;
	int height;
} GameSettings;

typedef struct {
	GameSettings *settings;
	SDL_Surface *screen;
	GameState next_state;
	GameLevel *level;
} GameInstance;

typedef struct {
	List *static_objects;
} GameLevel;

enum GameState {
	INTRO,
	MENU,
	LEVEL
};
