
#include <SDL2/SDL.h>
#include <GL/gl.h>

#include <iostream>
#include <vector>

#include <glm/glm.hpp>

#include "camera.h"
#include "context.h"
#include "globals.h"
#include "input.h"
#include "render.h"
#include "ticker.h"
#include "timer.h"



int main(int argc, char* args[]) {

    Context context;
    context_setup_window(context);
    context_setup_gl(context);
    
    input_init();
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

    // glColorMaterial(GL_FRONT_AND_BACK, GL_EMISSION);
    // glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    bool done = false;

    Ticker ticker;
    ticker_reset(ticker);
    ticker_set_one_tick(ticker, 5000.0f);
    ticker_start_one_tick(ticker);
    ticker_set(ticker, 1000.0f);
    ticker_start(ticker);

    while (!done) {

        timer_update(timer);

        done = input_pump_events();

        render_prepare_scene();

        //camera_debug_info(cam);
        camera_update(cam);
        camera_yaw_pitch_bounds_check(cam);
        
        draw_scene();


        context_window_swap(context);
        
        timer_frame_wait(timer);
        //timer_debug_info(timer);
        timer_increment_framecount(timer);

        if (ticker_update(ticker))
            std::cout << "TICK" << std::endl;

        if (ticker.one_tick_start_stop == true) {
            if (ticker_one_tick(ticker))
                std::cout << "5000ms - ONE TICK COMPLETED" << std::endl;
        }

    }

    context_destroy(context);

    return 0;
}