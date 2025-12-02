#pragma once

#include <SDL2/SDL.h>

constexpr float FPS_CAP = 120.0f;
constexpr float ONE_SECOND = 1000.0f;

struct Timer {
    float now;
    float last;
    float diff;
    float frame_count;
    float fps_cap;
};

void timer_reset(Timer& timer);
void timer_update(Timer& timer);
void timer_set_fps_cap(Timer& timer, const int fps);

float timer_frame_count(const Timer& timer);
float timer_compute_wait_time(const Timer& timer);
float timer_get_app_runing_time(const Timer& timer);

void timer_frame_wait(const Timer& timer);
float timer_compute_average_fps(const Timer& timer);
void timer_increment_framecount(Timer& timer);

void timer_debug_info(const Timer& timer);