#include "windowManager.h"

int createWindow(SDL_Window** window, SDL_Renderer** renderer) {

	//Initialization
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Error window initialization failed\n");
		return -1;
	}
	//Creating a window with SDL
	*window = SDL_CreateWindow("SDL_Project", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,WINDOW_WIDTH,WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	//Checking for error
	if (*window == NULL) {
		printf("Error when creating the window\n");
		SDL_Quit();
		return -1;
	}
	//Creating the renderer system
	*renderer = SDL_CreateRenderer(*window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//Checking for error
	if (*renderer == NULL) {
		printf("Error when processing the renderer\n");
		SDL_Quit();
		return -1;
	}
	return 0;
}
int closeWindow(SDL_Window* window) {

	SDL_Event event;

	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			return 1;
		}
	}
	return 0;
}

void drawImage(SDL_Renderer* renderer) {
	//SDL_Surface* BGSurface = SDL_LoadBMP("cat_player.bmp");
	SDL_Surface* BGSurface = SDL_LoadBMP("cat_player.bmp");

	if (!BGSurface) {
		printf("Error loading image:\n");
		return -1;
	}
	SDL_Texture* BGTexture = SDL_CreateTextureFromSurface
	(renderer, BGSurface);
	SDL_FreeSurface(BGSurface);

	if (!BGTexture) {
		printf("Error creating texture:\n");
	}
	SDL_Rect BGrect = {IMG_X,
		IMG_Y,IMG_WIDTH, IMG_HEIGHT};

	// Render and Clear
	SDL_RenderCopy(renderer, BGTexture, NULL, &BGrect);
	SDL_DestroyTexture(BGTexture);

	return 0;
}