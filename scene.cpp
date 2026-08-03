
#include "scene.h"


void add_entity(scene& scene, entity* entity) {
    scene.entities.emplace_back(entity);
}

std::vector<entity*> get_entities(scene& scene) {
    return scene.entities;
}