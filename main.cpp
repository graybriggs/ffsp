
#include <SDL2/SDL.h>
#include <GL/gl.h>

#include <iostream>
#include <vector>

#include <glm/glm.hpp>

#include "camera.h"
#include "context.h"
#include "globals.h"
#include "input.h"
#include "object.h"
#include "render.h"
#include "timer.h"



int main(int argc, char* args[]) {

    Context context;
    context_setup_window(context);
    context_setup_gl(context);


    bool done = false;
    //SDL_Event event;

    input_init();
    draw_init(SCREEN_WIDTH, SCREEN_HEIGHT);


    camera cam;
    camera_setup(cam, glm::vec3(0, 3.0, 3.0));


    Timer timer;
    timer_reset(timer);

    while (!done) {

        timer_update(timer);

        done = input_pump_events();

        render_prepare_scene();

        camera_debug_info(cam);
        camera_update(cam);
        
        draw_scene();

        camera_yaw_pitch_bounds_check(cam);

        context_window_swap(context);
        
        //timer_frame_wait(timer);
        timer_debug_info(timer);
        timer_increment_framecount(timer);
    }

    context_destroy(context);

    return 0;
}