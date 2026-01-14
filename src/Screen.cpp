// Screen.cpp

#include "Screen.h"


namespace particlesim {

Screen::Screen() : 
        m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(NULL) {
    
}


bool Screen::init() {

    // INITIALIZE SDL ==========================
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;  // Error getting SDL.
    }

    // CREATE WINDOW ===========================
    m_window = SDL_CreateWindow(
            "Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, WIN_W, WIN_H, SDL_WINDOW_SHOWN);
    
    if (m_window == NULL) {
        SDL_Quit();
        return false;  // Error creating an SDL window.
    }

    // SDL RENDERER ============================
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_STATIC, WIN_W, WIN_H);
    
    if (m_renderer == NULL) {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    if (m_texture == NULL) {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }


    // PIXEL DRAWING ===========================
    m_buffer1 = new Uint32[WIN_W*WIN_H];  // Ideally check this with exception handling
    m_buffer2 = new Uint32[WIN_W*WIN_H];  // Ideally check this with exception handling
    memset(m_buffer1, 0, WIN_W*WIN_H*sizeof(Uint32));
    memset(m_buffer2, 0, WIN_W*WIN_H*sizeof(Uint32));

    return true;
}


void Screen::update() {
    SDL_UpdateTexture(m_texture, NULL, m_buffer1, WIN_W*sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}


void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
    // Inefficient check; consider alternative check in real-world applications
    if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H) { return; }
    
    Uint32 color = 0;

    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 8;
    color += 0xFF;

    // Set pixel [x, y] to desired color
    m_buffer1[(y*WIN_W) + x] = color;
}


bool Screen::processEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) { return false; }
    }
    return true;
}


void Screen::boxBlur() {
    // Swap the buffers so pixel is in m_buffer2 and we are drawing to m_buffer1
    Uint32 *temp = m_buffer1;
    m_buffer1 = m_buffer2;
    m_buffer2 = temp;

    for (int y = 0, n = WIN_H; y < n; y++) {
        for (int x = 0, m = WIN_W; x < m; x++) {
            int redTotal = 0;
            int greenTotal = 0;
            int blueTotal = 0;
            for (int row = -1; row <= 1; row++) {
                for (int col = -1; col <= 1; col++) {
                    int currentX = x + col;
                    int currentY = y + row;
                    if (currentX >= 0 && currentX < WIN_W && currentY >= 0 && currentY < WIN_H) {
                        Uint32 color = m_buffer2[currentY*WIN_W + currentX];

                        Uint8 red = color >> 24;
                        Uint8 green = (color >> 16) & 0x000000FF;
                        Uint8 blue = (color >> 8) & 0x000000FF;

                        redTotal += red;
                        greenTotal = green;
                        blueTotal += blue;
                    }
                }
            }

            Uint8 red = redTotal/9;
            Uint8 green = greenTotal/9;
            Uint8 blue = blueTotal/9;

            setPixel(x, y, red, green, blue);
        }
    }
}


void Screen::close() {
    // CLOSING =================================
    delete [] m_buffer1;
    delete [] m_buffer2;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);

    SDL_Quit();  // Close SDL connection
}

} /* namespace particlesim */