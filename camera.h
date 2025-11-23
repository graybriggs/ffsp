#pragma once

#include <GL/gl.h>
#include <glm/glm.hpp>


struct camera {
    glm::vec3 eye;
    glm::vec3 center;
    glm::vec3 forward;
    glm::vec3 right;
    glm::vec3 up;
    double cam_yaw;
    double cam_pitch;
    float speed = 0.1f;
    float rot_speed = 0.5f;
};

constexpr double PI = 3.14159265;
constexpr glm::vec3 WORLD_UP = glm::vec3(0.0, 1.0, 0.0);

constexpr float DEG2RAD(float ang) {
    return ang * (PI / 180.0);
}

void camera_setup(camera& cam, glm::vec3 pos, double yaw = 0.0, double pitch = 0.0);
void compute_basis(camera& cam);
glm::vec3 compute_forward(camera& cam);
glm::vec3 compute_right(camera& cam);
glm::vec3 compute_up(camera& cam);


void make_perspective(GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar);
void look_at(glm::vec3 center, glm::vec3 eye, glm::vec3 up);

void camera_yaw_pitch_bounds_check(camera& camera);

void camera_debug_info(camera& camera);

void camera_update(camera& camera);