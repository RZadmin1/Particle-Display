// Screen.h


#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace particlesim {

class Screen {

public:
    const static int WIN_W = 800;
    const static int WIN_H = 600;

private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer1;
    Uint32 *m_buffer2;
    
public:
    Screen();
    bool init();
    void update();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    bool processEvents();
    void boxBlur();
    void fastBoxBlur();
    void close();
};

} /* namespace particlesim */

#endif /* SCREEN_H_ */