
#include <SDL2/SDL.h>
#include <GL/gl.h>

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include <glm/glm.hpp>

#include "camera.h"
#include "context.h"
#include "cube.h"
#include "globals.h"
#include "input.h"
#include "render.h"
#include "scene.h"
#include "ticker.h"
#include "timer.h"



int main(int argc, char* args[]) {
    std::srand(std::time(nullptr));
    Context context;
    context_setup_window(context);
    context_setup_gl(context);

    input_state input;
    input_init(input);

    draw_init(SCREEN_WIDTH, SCREEN_HEIGHT);
    
    camera cam;
    glm::vec3 starting_position = glm::vec3(0.0, 3.0, 3.0);
    camera_setup(cam, starting_position);
    
    Timer timer;
    timer_reset(timer);
    
    GLfloat light_ambient[] = {0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat light_diffuse[] = {1.0f, 0.2f, 0.2f, 1.0f};
    GLfloat light_position[] = {1.0f, 1.0f, 0.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glColorMaterial(GL_FRONT_AND_BACK, GL_EMISSION);
    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    bool done = false;

    Ticker ticker;
    ticker_reset(ticker);
    ticker_set(ticker, 1000.0f);
    ticker_start(ticker);
    
    OneTick ot;
    one_tick_set(ot, 5000.0f);
    one_tick_start(ot);


    Cube c;
    cube_setup(c);

    entity e0;
    entity_setup(e0, entity_geometry::CUBE);
    e0.model = glm::translate(e0.model, glm::vec3(0.0, 0.0, 0.0));
    //e0.position = glm::vec3(0.0, 0.0, 0.0);
    entity e1;
    entity_setup(e1, entity_geometry::PYRAMID);
    //e1.position = glm::vec3(-5.0, 0.0, -5.0);
    e0.model = glm::translate(e0.model, glm::vec3(-5.0, 0.0, -5.0));
    entity e2;
    entity_setup(e2, entity_geometry::PLANE);
    //e1.position = glm::vec3(-5.0, 0.0, -5.0);
    e0.model = glm::translate(e2.model, glm::vec3(-10.0, 10.0, 10.0));


    scene test_scene;
    //glm::vec3 position(0.0, 0.0, 0.0);
    add_entity(test_scene, &e0);
    add_entity(test_scene, &e1);
    add_entity(test_scene, &e2);

    while (!input_quit(input)) {

        timer_update(timer);

        input_pump_events(input);

        render_prepare_scene(cam);
        
        //camera_debug_info(cam);
        camera_update(cam, input);
        camera_yaw_pitch_bounds_check(cam);
        
        auto delta = timer_get_delta_time(timer);
        //cube_update(c, delta);
        if (input_query_key_state(input, INPUT_KEY_Y)) {
            e0.position.z += 1.0;
        }
        if (input_query_key_state(input, INPUT_KEY_H)) {
            e0.position.z -= 1.0;
        }
        
        //draw_cube(position);
        

        draw_entities(cam, test_scene);
        //draw_game_cube(c);

        context_window_swap(context);
        
        //timer_debug_info(timer);
        timer_increment_framecount(timer);

        // if (ticker_update(ticker))
        //     std::cout << "REPEATED TICK" << std::endl;

        // if (ticker.one_tick_is_running == true) {
        //     if (one_tick_done(ticker))
        //         std::cout << "5000ms - ONE TICK COMPLETED" << std::endl;
        // }

    }

    context_destroy(context);

    return 0;
}