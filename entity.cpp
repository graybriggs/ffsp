
#include "entity.h"


//void entity_setup(entity& e, entity_type et, entity_geometry ebg, glm::vec3 bp) {
void entity_setup(entity& e, const entity_geometry& eg) {
    // e.base_position = bp;
    // e.position = e.base_position;

    // e.e_type = et;
    e.e_geometry = eg;
    e.model = glm::mat4(1.0f);
    e.e_base_color = entity_base_color::WHITE;
    e.viewable = true;
}