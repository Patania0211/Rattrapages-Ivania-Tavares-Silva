#include "constants.h"
#include <stdio.h>
#include <SDL.h>

#pragma once

int createWindow(SDL_Window** window, SDL_Renderer** renderer);
int closeWindow(SDL_Window* window);
int drawImage(SDL_Renderer* renderer);