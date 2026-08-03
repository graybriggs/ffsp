#pragma once

#include <GL/gl.h>
#include <glm/glm.hpp>
#include "input.h"

// view data
struct camera {
    glm::vec3 eye;
    glm::vec3 center;
    glm::vec3 forward;
    glm::vec3 right;
    glm::vec3 up;
    double cam_yaw;
    double cam_pitch;
    float speed = 0.2f;
    float rot_speed = 0.4f;
    glm::mat4 perspective;
    glm::mat4 view;
};

constexpr glm::vec3 WORLD_UP = glm::vec3(0.0, 1.0, 0.0);


void camera_setup(camera& cam, glm::vec3 pos, double yaw = 0.0, double pitch = 0.0);
void compute_basis(camera& cam);
glm::vec3 compute_forward(camera& cam);
glm::vec3 compute_right(camera& cam);
glm::vec3 compute_up(camera& cam);


glm::mat4 make_perspective(GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar);
glm::mat4 look_at(glm::vec3 center, glm::vec3 eye, glm::vec3 up);

void camera_yaw_pitch_bounds_check(camera& camera);

void camera_debug_info(camera& camera);

void camera_update(camera& camera, input_state& input);