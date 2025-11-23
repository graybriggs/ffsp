
#include "context.h"
#include "globals.h"

#include <iostream>

void context_setup_window(Context& context) {
    SDL_Init(SDL_INIT_VIDEO);
    context.window = SDL_CreateWindow(
        "FF-OGL",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        static_cast<int>(SCREEN_WIDTH),
        static_cast<int>(SCREEN_HEIGHT),
        SDL_WINDOW_OPENGL
    );
    if (!context.window) {
        std::cout << "CreateWindow error" << std::endl;
    }
}

void context_setup_gl(Context& context) {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    context.gl_context = SDL_GL_CreateContext(context.window);
    if (!context.gl_context) {
        std::cout << "GL Context creaton error" << std::endl;
    }

    SDL_GL_MakeCurrent(context.window, context.gl_context);
}


void context_window_swap(Context& context) {
    SDL_GL_SwapWindow(context.window);
}

void context_destroy(Context& context) {
    SDL_GL_DeleteContext(context.gl_context);
    SDL_DestroyWindow(context.window);
    SDL_Quit();
}
