// PARTICLE-DISPLAY
// main.cpp

#include <iostream>
#include <stdlib.h>
#include <SDL.h>
#include <math.h>

#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace particlesim;



int main()
{
    srand(time(NULL));

    Screen screen;

    if (screen.init() == false) {
        cout << "Error initializing SDL." << endl;
    }

    int centerX = Screen::WIN_W/2;
    int centerY = Screen::WIN_H/2;

    // INITIALIZE SWARM ========================
    Swarm swarm;


    // MAIN LOOP =============================== 
    while (true) {
        // Update particles
        

        // Draw particles
        int elapsed = SDL_GetTicks();

        screen.clear();
        swarm.update(elapsed);

        unsigned char red = (unsigned char)((1 + sin(elapsed/2 * 0.001)) * 128);
        unsigned char green = (unsigned char)((1 + sin(elapsed/2 * 0.002)) * 128);
        unsigned char blue = (unsigned char)((1 + sin(elapsed/2 * 0.003)) * 128);
        
        const Particle * const pParticles = swarm.getParticles();
        for (int i = 0, n = Swarm::NPARTICLES; i < n; i++) {
            Particle particle = pParticles[i]; // Pointer to a particle

            
            int x = (particle.m_x + 1) * centerX;
            int y = (particle.m_y * centerX) + centerY;

            screen.setPixel(x, y, red, green, blue);
        }

        // Draw the screen
        screen.update();

        // Check for messages/events
        if (screen.processEvents() == false) { break; }
    }

    screen.close();    

    return 0;  // End of program.
}