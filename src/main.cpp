// PARTICLE-DISPLAY
// main.cpp

#include <iostream>
#include <SDL.h>

using namespace std;



int main()
{
    // VARIABLES ===============================
    const int WIN_W = 800;  // Window WIDTH
    const int WIN_H = 600;  // Window HEIGHT

    // INITIALIZE SDL ==========================
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "SDL initialization failed." << endl;
        return 1;  // Error getting SDL.
    }

    // CREATE WINDOW ===========================
    SDL_Window *window = SDL_CreateWindow(
            "Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, WIN_W, WIN_H, SDL_WINDOW_SHOWN);
    
    if (window == NULL) {
        cerr << "Could not create window: " << SDL_GetError() << endl;
        SDL_Quit();
        return 2;  // Error creating an SDL window.
    }

    // SDL RENDERER ============================
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_STATIC, WIN_W, WIN_H);
    
    if (renderer == NULL) {
        cerr << "Could not create renderer." << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 3;
    }
    if (texture == NULL) {
        cout << "Could not create texture." << endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 4;
    }


    // PIXEL DRAWING ===========================
    Uint32 *buffer = new Uint32[WIN_W*WIN_H];  // Ideally check this with exception handling

    memset(buffer, 0xFF, WIN_W*WIN_H*sizeof(Uint32));

    SDL_UpdateTexture(texture, NULL, buffer, WIN_W*sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);


    // MAIN LOOP ===============================
    bool quit = false;
    SDL_Event event;

    while (!quit) {
        // Update particles
        // Draw particles
        // Check for messages/events

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) { quit = true; }
        }
    }


    // CLOSING =================================
    delete [] buffer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);

    cout << "Closing window ..." << endl;
    SDL_DestroyWindow(window);
    
    cout << "Closing program ..." << endl;
    SDL_Quit();  // Close SDL connection

    return 0;  // End of program.
}