#pragma once
#include "constants.h"
#include <SDL_image.h>
#include <stdio.h>
#include <SDL.h>



typedef struct Player {
	int x;
	int y;
	int w;
	int h;
	int velocity;
}Player;

int drawPlayer(Player player, SDL_Renderer* renderer);
int movePlayer(Player* player);
int playerCollisions(Player* player);

