// Screen.h


#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace particles {

class Screen {

public:
    const static int WIN_W = 800;
    const static int WIN_H = 600;

private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer;
    
public:
    Screen();
    bool init();
    bool processEvents();
    void close();

};

} /* namespace particles */

#endif /* SCREEN_H_ */