#include "constants.h"
#include <stdio.h>
#include <SDL.h>
#include "windowManager.h"
#include "playerManager.h"


int quit = 0;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

SDL_Surface* playerSurface = NULL;
//Player player {}
Player player = { DEFAULT_POSITION,DEFAULT_POSITION,
    PLAYER_WIDTH,PLAYER_HEIGHT,PLAYER_VELOCITY };

int main(int argc, char* argv[]) {
    if (createWindow(&window, &renderer) != 0) {
        return -1;
    }
    if (renderer == NULL) {
        printf("Erreur creation rendu SDL");
        SDL_Quit();
        return -1;
    }

    while (!quit) {
        quit = closeWindow(window);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        //CALLING IMAGE RELATED FUNCTIONS
        drawImage(renderer);

        //CALLING PLAYER RELATED FUNCTIONS
        drawPlayer(player, renderer);
        movePlayer(&player);
        playerCollisions(&player);

        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

