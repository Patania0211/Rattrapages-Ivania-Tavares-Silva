#include "playerManager.h"


int drawPlayer(Player player, SDL_Renderer* renderer) {
    //Function handling the displaying of the player on the screen
    SDL_Rect playerRect = { player.x, player.y, player.w, player.h };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 1);
    SDL_RenderFillRect(renderer, &playerRect);
    return 0;
}

int movePlayer(Player* player) {
    // Function handling the player movement
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_UP]) {
        player->y -= player->velocity;
    }
    if (state[SDL_SCANCODE_DOWN]) {
        player->y += player->velocity;
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        player->x += player->velocity;
    }
    if (state[SDL_SCANCODE_LEFT]) {
        player->x -= player->velocity;
    }

    return 0;
}

int playerCollisions(Player* player) {
    // Ensure player stays within the window boundaries
    if (player->y < 0) {
        player->y = 0;
    }
    if (player->y > WINDOW_HEIGHT - PLAYER_HEIGHT) {
        player->y = WINDOW_HEIGHT - PLAYER_HEIGHT;
    }
    if (player->x < 0) {
        player->x = 0;
    }
    if (player->x > WINDOW_WIDTH - PLAYER_WIDTH) {
        player->x = WINDOW_WIDTH - PLAYER_WIDTH;
    }
}