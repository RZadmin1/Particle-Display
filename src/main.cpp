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
    while (true) {
        // Update particles
        // Draw particles
        // Check for messages/events

        if (Screen.processEvents() == false) {
            break;
        }
    }

    Screen.close();    

    return 0;  // End of program.
}