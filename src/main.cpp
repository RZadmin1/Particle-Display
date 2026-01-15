// PARTICLE-DISPLAY
// main.cpp

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include <bitset>
#include <math.h>

#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace particlesim;



int main()
{
    srand(time(NULL));

    Screen screen;
    int algo = 1; // Regular Box Blur by default

    // CHOOSE ALGORITHM ========================
    string input;
    while (true) {
        cout << "Choose a blur algorithm: " << endl;
        cout << "\t1. Box Blur" << endl;
        cout << "\t2. Fast Box Blur" << endl;
        cout << "\tOr press 'Q' to quit." << endl;
        cout << "Enter a choice: ";

        cin >> input;

        if (input[0] == 'q' || input[0] == 'Q') {
            cout << "Goodbye." << endl;
            return 0; // End program.
        } else if (input[0] == '1') {
            cout << "Running REGULAR BOX BLUR Particle Screen..." << endl;
            algo = 1;
            break;
        } else if (input[0] == '2') {
            cout << "Running FAST BOX BLUR Particle Screen..." << endl;
            algo = 2;
            break;
        } else {
            cout << "Invalid input. Please try again." << endl;
        }
    }


    // INITIALIZE SCREEN =======================
    if (screen.init() == false) {
        cout << "Error initializing SDL." << endl;
    }

    int centerX = Screen::WIN_W/2;
    int centerY = Screen::WIN_H/2;
    

    // INITIALIZE SWARM ========================
    Swarm swarm;


    // MAIN LOOP ===============================
    while (true) {
        Uint64 start = SDL_GetPerformanceCounter();

        // Draw particles
        Uint32 elapsed = SDL_GetTicks();

        swarm.update(elapsed);

        Uint8 red = (Uint8)((1 + cos(elapsed/5 * 0.001)) * 128);
        Uint8 green = (Uint8)((1 + sin(elapsed/5 * 0.002)) * 128);
        Uint8 blue = (Uint8)((1 + sin(elapsed/5 * 0.003)) * 128);

        const Particle * const pParticles = swarm.getParticles();
        for (int i = 0, n = Swarm::NPARTICLES; i < n; i++) {
            Particle particle = pParticles[i]; // Pointer to a particle

            int x = (particle.m_x + 1) * centerX;
            int y = (particle.m_y * centerX) + centerY;

            screen.setPixel(x, y, red, green, blue);
        }

        if (algo == 1) {
            screen.boxBlur();
        } else {
            screen.fastBoxBlur();
        }


        // Draw the screen
        screen.update();

        Uint64 end = SDL_GetPerformanceCounter();
        double deltaTime = (double)(end - start) / (double)SDL_GetPerformanceFrequency();
        cout << "FPS: " << 1.0 / deltaTime << endl;


        // Check for messages/events
        if (screen.processEvents() == false) { break; }
    }

    screen.close();    

    return 0;  // End of program.
}