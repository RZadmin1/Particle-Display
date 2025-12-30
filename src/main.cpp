// PARTICLE-DISPLAY
// main.cpp

#include <iostream>
#include <SDL.h>

using namespace std;



int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "SDL initialization failed." << endl;
        return 1; // ERROR GETTING SDL
    }

    cout << "Success!" << endl;

    SDL_Quit();
}