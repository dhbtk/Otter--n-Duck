#include "SDL.h"
#include "SDL_collide.h"
#include <glib.h>

typedef struct {
	GList* objects;
	int x_dimension;
	int y_dimension;
	player_object* player;
} game_field;

typedef struct {
	SDL_Surface* sprite;
	int x_pos;
	int y_pos;
	int layer; // The lower, the farther down it will be
	int can_collide;
} game_object;

typedef struct {
	int health;
	int maxhealth;
	game_object* object;
	int x_vel;
	int y_vel;
	int attacking;
	int direction; // -1 is left, 1 is right
} player_object;

game_field* start_game_field() {
	game_field* field = malloc(sizeof(game_field));
	field->objects = NULL;
	field->x_dimension = 640;
	field->y_dimension = 480;
	
	field->player = malloc(sizeof(player_object));
	field->player->maxhealth = 150;
	field->player->health = field->player->maxhealth;
	field->player->x_vel = 0;
	field->player->y_vel = 0;
	field->player->attacking = FALSE;
	field->player->direction = 1;
}

game_object* spawn_object(int x_pos,int y_pos,int layer,char* sprite_path);
