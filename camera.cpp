
#include "camera.h"
#include "input.h"

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>



void camera_setup(camera& cam, glm::vec3 pos, double yaw, double pitch) {
    cam.eye = pos;
    cam.center = glm::vec3(0,0,0);
    cam.right = glm::normalize(glm::cross(cam.eye - cam.center, WORLD_UP));
    cam.cam_yaw = yaw;
    cam.cam_pitch = pitch;
}

void compute_basis(camera& cam) {
    glm::vec3 forward = glm::normalize(cam.center - cam.eye);
    glm::vec3 right = glm::normalize(glm::cross(forward, WORLD_UP));
    glm::vec3 up = glm::normalize(glm::cross(forward, right));
    cam.forward = forward;
    cam.right = right;
    cam.up = up;
}

glm::vec3 compute_forward(camera& cam) {
    auto yaw = cam.cam_yaw;
    auto pitch = cam.cam_pitch;

    glm::vec3 angle(
        glm::cos(glm::radians(yaw)) * glm::cos(glm::radians(pitch)),
        glm::sin(glm::radians(pitch)),
        glm::sin(glm::radians(yaw)) * glm::cos(glm::radians(pitch))
    );
    return glm::normalize(angle);
}

glm::vec3 compute_right(camera& cam) {

    return glm::normalize(glm::cross(compute_forward(cam), WORLD_UP));
}
glm::vec3 compute_up(camera& cam) {

    return glm::normalize(glm::cross(compute_forward(cam), compute_right(cam)));
}

void make_perspective(GLfloat fovy, GLfloat aspect, GLfloat z_near, GLfloat z_far) {
    float far = 1.0 / (glm::tan(DEG2RAD(fovy) / 2.0) * aspect);
    float f = 1.0 / glm::tan(DEG2RAD(fovy) / 2.0);

    float m[16] = {
        far, 0, 0, 0,
        0, f, 0, 0,
        0, 0, (-z_far - z_near) / (z_near - z_far), -(2 * z_far * z_near) / (z_near - z_far),
        0, 0, -1, 0
    };

    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(m);
}

void look_at(glm::vec3 eye, glm::vec3 center, glm::vec3 arbitary_up) {

    glm::vec3 forward = glm::normalize(center - eye);
    glm::vec3 right = glm::normalize(glm::cross(forward, glm::normalize(arbitary_up)));
    glm::vec3 up = glm::normalize(glm::cross(forward, right));

    float tx = glm::dot(right, eye);
    float ty = glm::dot(up, eye);
    float tz = glm::dot(forward, eye);

    GLfloat m[16] = {
        right.x, up.x, -forward.x, 0,
        right.y, up.y, -forward.y, 0,
        right.z, up.z, -forward.z, 0,
        -tx    , -ty ,  tz       , 1
    };
    glLoadMatrixf(m);
}


void camera_yaw_pitch_bounds_check(camera& camera) {

    if (camera.cam_yaw < 0.0)
        camera.cam_yaw = 360.0;
    else if (camera.cam_yaw >= 360.0)
        camera.cam_yaw = 0.0;
    if (camera.cam_pitch < 0.0)
        camera.cam_pitch = 360.0;
    else if (camera.cam_pitch >= 360.0)
        camera.cam_pitch = 0.0;
}

void camera_debug_info(camera& camera) {
    std::cout << "Camera position: (" << camera.eye.x << " " << camera.eye.y << " " << camera.eye.z << ")";
    std::cout << "\t";
    std::cout << "yaw: " << camera.cam_yaw << " pitch: " << camera.cam_pitch <<  std::endl;
}

void camera_update(camera& camera) {
    glm::vec3 forward = compute_forward(camera);
    glm::vec3 right = compute_right(camera);

    if (input_state_button(button::INPUT_KEY_W)) {
        camera.eye += forward * camera.speed;
    }
    if (input_state_button(button::INPUT_KEY_S)) {
        camera.eye -= forward * camera.speed;
    }
    if (input_state_button(button::INPUT_KEY_A)) {
        camera.eye += right * camera.speed;
    }
    if (input_state_button(button::INPUT_KEY_D)) {
        camera.eye -= right * camera.speed;
    }
    if (input_state_button(button::INPUT_KEY_RIGHT)) {
        camera.cam_yaw -= camera.rot_speed;
        camera.center = camera.eye + compute_forward(camera);
    }
    if (input_state_button(button::INPUT_KEY_LEFT)) {
        camera.cam_yaw += camera.rot_speed;
        camera.center = camera.eye + compute_forward(camera);
    }
    if (input_state_button(button::INPUT_KEY_UP)) {
        camera.cam_pitch -= camera.rot_speed;
        camera.center = camera.eye + compute_forward(camera);
    }
    if (input_state_button(button::INPUT_KEY_DOWN)) {
        camera.cam_pitch += camera.rot_speed;
        camera.center = camera.eye + compute_forward(camera);
    }

    camera.center = camera.eye + compute_forward(camera);
    look_at(camera.eye, camera.center, compute_up(camera));
}