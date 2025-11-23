#pragma once

#include <SDL2/SDL.h>

struct Context {
    SDL_Window* window;
    SDL_GLContext gl_context;
};

void context_setup_window(Context& context);
void context_setup_gl(Context& context);
void context_window_swap(Context& context);
void context_destroy(Context& context);