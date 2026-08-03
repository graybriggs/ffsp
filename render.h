
#pragma once

#include "camera.h"
#include "cube.h"
#include "entity.h"
#include "scene.h"

#include <glm/gtc/type_ptr.hpp>

#include <vector>

void draw_init(double screen_w, double screen_h);
void draw_cube();
void draw_cube(const glm::vec3 position);
void draw_game_cube(const Cube& cube);
void draw_pyramid();
void draw_plane_triangle();
void draw_scene();
void draw_scene(glm::vec3 position);
void draw_entities(camera& cam, scene& e);
void test_tiles();

void render_prepare_scene(camera& cam);