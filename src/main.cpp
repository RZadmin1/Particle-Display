// PARTICLE-DISPLAY
// main.cpp

#include <iostream>
#include <SDL.h>
#include <math.h>

#include "Screen.h"

using namespace std;
using namespace particles;



int main()
{
    Screen screen;

    if (screen.init() == false) {
        cout << "Error initializing SDL." << endl;
    }

    // MAIN LOOP =============================== 
    while (true) {
        // Update particles
        

        // Draw particles
        int elapsed = SDL_GetTicks();
        unsigned char red = (unsigned char)((1 + sin(elapsed * 0.001)) * 128);
        unsigned char green = (unsigned char)((1 + sin(elapsed * 0.002)) * 128);
        unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.003)) * 128);

        for (int y = 0; y < Screen::WIN_H; y++) {
            for (int x = 0; x < Screen::WIN_W; x++) {
                screen.setPixel(x, y, red, green, blue);
            }
        }
        
        // Draw the screen
        screen.update();

        // Check for messages/events
        if (screen.processEvents() == false) { break; }
    }

    screen.close();    

    return 0;  // End of program.
}