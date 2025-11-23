
#pragma once

#include "camera.h"

#include <vector>

void draw_init(double screen_w, double screen_h);
void draw_cube();
void draw_pyramid();
void draw_triangle();
void draw_scene();

void render_prepare_scene();
void render_swap();