// PARTICLE-DISPLAY
// main.cpp

#include <iostream>
#include <SDL.h>

#include "Screen.h"

using namespace std;
using namespace particles;



int main()
{
    Screen Screen;

    if (Screen.init() == false) {
        cout << "Error initializing SDL." << endl;
    }

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

    Screen.close();    

    return 0;  // End of program.
}