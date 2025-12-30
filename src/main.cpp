// PARTICLE-DISPLAY
// main.cpp

#include <iostream>
#include <SDL.h>

using namespace std;



int main()
{
    const int WIN_W = 800;  // Window WIDTH
    const int WIN_H = 600;  // Window HEIGHT

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "SDL initialization failed." << endl;
        return 1;  // Error getting SDL.
    }

    SDL_Window *window = SDL_CreateWindow(
            "Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, WIN_W, WIN_H, SDL_WINDOW_SHOWN);
    
    if (window == NULL) {
        cerr << "Could not create window: " << SDL_GetError() << endl;
        SDL_Quit();
        return 2;  // Error creating an SDL window.
    }


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

    cout << "Closing window ..." << endl;
    SDL_DestroyWindow(window);
    
    cout << "Closing program ..." << endl;
    SDL_Quit();  // Close SDL connection

    return 0;  // End of program.
}