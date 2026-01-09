// Screen.cpp

#include "Screen.h"

namespace particles {

Screen::Screen() : 
        m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {
    
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
    m_buffer = new Uint32[WIN_W*WIN_H];  // Ideally check this with exception handling
    
    memset(m_buffer, 0, WIN_W*WIN_H*sizeof(Uint32));
    
    for (int i = 0; i < WIN_W*WIN_H; i++) {
        m_buffer[i] = 0xffff00ff;
    }


    // RENDERING ================================
    SDL_UpdateTexture(m_texture, NULL, m_buffer, WIN_W*sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);

    return true;
}


bool Screen::processEvents() {
    SDL_Event event;
    
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) { return false; }
    }
    return true;
}


void Screen::close() {
    // CLOSING =================================
    delete [] m_buffer;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);

    SDL_Quit();  // Close SDL connection
}

} /* namespace particles */