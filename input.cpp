#include <cstring>
#include <iostream>
#include <string>

#include <SDL2/SDL.h>

#include "input.h"

//static const char* button_names[] = {
//
//	[0] = "UP",
//	[INPUT_KEY_DOWN] = "DOWN",
//	[INPUT_KEY_LEFT] = "LEFT",
//	[INPUT_KEY_RIGHT] = "RIGHT",
//	[INPUT_KEY_G] = "G",
//	[INPUT_KEY_X] = "X",
//	[INPUT_KEY_Z] = "Y"
//};


//static bool key_bindings[button::INPUT_BUTTON_MAX];


void input_init(input_data& input) {
	input_clear_all_inputs(input);

	input.mouse_left = false;
	input.mouse_right = false;

	input.quit = false;
}

void input_set_left_mouse_click(input_data& input) {
    input.mouse_left = true;
}

void input_set_left_mouse_release(input_data& input) {
    input.mouse_left = false;
}

void input_set_right_mouse_click(input_data& input) {
    input.mouse_right = true;
}

void input_set_right_mouse_release(input_data& input) {
    input.mouse_right = false;
}


mouse_coords input_get_mouse_coords(input_data& input) {
	return input.coords;
}


void input_set_button_state(input_data& input, float state) {
	//input.key_bindings[button] = state;
}

void input_set_button_pressed(input_data& input, input_key_list button) {

	/*
	if (button < 0 || button > INPUT_BUTTON_MAX) {
		printf("Invaid button press\n");
		return;
	}
	*/

	input.key_bindings[button] = true;
}

void input_set_button_release(input_data& input, input_key_list button) {

	//if (button < 0 || button > INPUT_BUTTON_MAX) {
	//	return;
	//}

	input.key_bindings[button] = false;
}

bool input_query_button_state(input_data& input, input_key_list button) {
	return input.key_bindings[button];
}

void input_clear_all_inputs(input_data& input) {
	memset(&input.key_bindings[0], 0, sizeof(input.key_bindings));
}

const char* input_button_name(input_data& button) {
	//return button_names[button];
	return nullptr;
}


bool input_pump_events(input_data& input) {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			//app_done = true;
			return true;
		}

		if (event.type == SDL_KEYDOWN) {
			//int code = event.key.keysym.scancode;
			int code = event.key.keysym.sym;

			int internal_code = code;
			//printf("%X | %d\n", code, internal_code);
			switch (code) {
			case SDLK_ESCAPE:
				return true;
			case SDLK_SPACE:
				input_set_button_pressed(input, INPUT_KEY_SPACE);
				break;
			case SDLK_LEFT:
				input_set_button_pressed(input, INPUT_KEY_LEFT);
				break;
			case SDLK_RIGHT:
				input_set_button_pressed(input, INPUT_KEY_RIGHT);
				break;
			case SDLK_UP:
				input_set_button_pressed(input, INPUT_KEY_UP);
				break;
			case SDLK_DOWN:
				input_set_button_pressed(input, INPUT_KEY_DOWN);
				break;
			case SDLK_g:
				input_set_button_pressed(input, INPUT_KEY_G);
				break;
			case SDLK_h:
				input_set_button_pressed(input, INPUT_KEY_H);
				break;
			case SDLK_x:
				input_set_button_pressed(input, INPUT_KEY_X);
				break;
			case SDLK_z:
				input_set_button_pressed(input, INPUT_KEY_Z);
				break;
            case SDLK_w:
				input_set_button_pressed(input, INPUT_KEY_W);
				break;
            case SDLK_a:
				input_set_button_pressed(input, INPUT_KEY_A);
				break;
            case SDLK_s:
				input_set_button_pressed(input, INPUT_KEY_S);
				break;
            case SDLK_d:
				input_set_button_pressed(input, INPUT_KEY_D);
				break;

			}
		}
		else if (event.type == SDL_KEYUP) {
			//int code = event.key.keysym.scancode;
			int code = event.key.keysym.sym;
			int internal_code = code;
			//printf("%X | %d\n", code, internal_code);
			//input_set_button_released(internal_code);
			switch (code) {
			case SDLK_SPACE:
				input_set_button_release(input, INPUT_KEY_SPACE);
				break;
			case SDLK_LEFT:
				input_set_button_release(input, INPUT_KEY_LEFT);
				break;
			case SDLK_RIGHT:
				input_set_button_release(input, INPUT_KEY_RIGHT);
				break;
			case SDLK_UP:
				input_set_button_release(input, INPUT_KEY_UP);
				break;
			case SDLK_DOWN:
				input_set_button_release(input, INPUT_KEY_DOWN);
				break;
			case SDLK_g:
				input_set_button_release(input, INPUT_KEY_G);
				break;
			case SDLK_h:
				input_set_button_release(input, INPUT_KEY_H);
				break;
			case SDLK_x:
				input_set_button_release(input, INPUT_KEY_X);
				break;
			case SDLK_z:
				input_set_button_release(input, INPUT_KEY_Z);
				break;
            case SDLK_w:
				input_set_button_release(input, INPUT_KEY_W);
				break;
            case SDLK_a:
				input_set_button_release(input, INPUT_KEY_A);
				break;
            case SDLK_s:
				input_set_button_release(input, INPUT_KEY_S);
				break;
            case SDLK_d:
				input_set_button_release(input, INPUT_KEY_D);
				break;

			}
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				input_set_left_mouse_click(input);
				input.coords.mouse_x = event.button.x;
				input.coords.mouse_y = event.button.y;
				std::cout << input_get_mouse_coords(input).mouse_x << ", " << input_get_mouse_coords(input).mouse_y << std::endl;
			}
			if (event.button.button == SDL_BUTTON_RIGHT) {
				input_set_left_mouse_click(input);
			}

		}
		else if (event.type == SDL_MOUSEBUTTONUP) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				input_set_left_mouse_release(input);
				input.coords.mouse_x = event.button.x;
				input.coords.mouse_y = event.button.y;
			}
			if (event.button.button == SDL_BUTTON_RIGHT) {
				input_set_left_mouse_release(input);
			}
		}
	}
    return false;
}