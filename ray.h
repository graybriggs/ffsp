#pragma once

#include <glm/glm.hpp>

struct ray {
    glm::vec4 origin;
    glm::vec4 direction;
};

struct sphere {
    glm::vec3 position;
    float radius;
};

// calcualte NDC
// create clip space position
// convert to view space
// convert to world space
// ----
// cast ray
// check if ray intersects sphere / geometry ?? 

struct mouse_coords;

ray cast_ray(const mouse_coords& mcursor, const glm::mat4& projection, const glm::mat4& view);
bool ray_sphere_intersect(const ray& ray, const sphere& sphere);