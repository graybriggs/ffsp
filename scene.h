#pragma once

#include "camera.h"
#include "entity.h"

struct scene {
    std::vector<entity*> entities;
};

void add_entity(scene& scene, entity* entity);
std::vector<entity*> get_entities(scene& scene);