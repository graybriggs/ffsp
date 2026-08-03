
#pragma once

#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

enum class entity_type {
    textured_model,
    untextured_model
};

enum class entity_base_color {
    RED, GREEN, BLUE, WHITE, BLACK, CYAN, PURPLE, YELLOW
};

enum class entity_geometry {
    CUBE, PLANE, PYRAMID, SPHERE, MODEL, NONE
};

struct entity {

    entity_type e_type;
    entity_geometry e_geometry;
    entity_base_color e_base_color;

    bool viewable;
    glm::vec3 base_position;
    glm::vec3 position;
    // an entiy has its own model matrix
    glm::mat4 model;



    // base color ??
    // texture ??
    // geometry

};

//typedef std::vector<entity> entities;
using entities = std::vector<entity>;

//void entity_setup(entity& e, entity_type et, entity_base_geometry ebt, glm::vec3 bp);
void entity_setup(entity& e, const entity_geometry& eg);