
#include "timer.h"

#include <iostream>

void timer_reset(Timer& timer) {
    timer.now = 0;
    timer.last = 0;
    timer.diff = 0;
    timer.frame_count = 0;
    timer.fps_cap = FPS_CAP;
}

void timer_update(Timer& timer) {
    timer.now = SDL_GetTicks64();
    timer.diff = timer.now - timer.last;
    timer.last = timer.now;
}

void timer_set_fps_cap(Timer& timer, const float fps) {
    timer.fps_cap = fps;
}

float timer_frame_count(const Timer& timer) {
    return SDL_GetTicks64() + (ONE_SECOND / timer.fps_cap);
}

float timer_compute_wait_time(const Timer& timer) {
    return SDL_GetTicks64() + (ONE_SECOND / timer.fps_cap) - timer.now;
}


float timer_get_app_runing_time(const Timer& timer) {
    return SDL_GetTicks64() / ONE_SECOND;
}

void timer_frame_wait(const Timer& timer) {
    
    if (timer.now < timer_frame_count(timer)) {
        SDL_Delay(timer_compute_wait_time(timer));
    }
}

float timer_compute_average_fps(const Timer& timer) {
    
    auto average_fps = timer.frame_count / (SDL_GetTicks64() / ONE_SECOND);
    if (average_fps > 2000000.0f) {
        average_fps = 0;
    }
    return average_fps;
}

void timer_increment_framecount(Timer& timer) {
    timer.frame_count++;
}


void timer_debug_info(const Timer& timer) {
    std::cout << "Running Time: " << timer_get_app_runing_time(timer) << " seconds " << std::endl;
    std::cout << "Average FPS: " << timer_compute_average_fps(timer) << std::endl;
}