#include <array>
#include <cstring>
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


static std::array<int, button::INPUT_BUTTON_MAX> key_bindings;

//static bool key_bindings[button::INPUT_BUTTON_MAX];


void input_init() {
	input_clear_all_inputs();
}

void input_set_button_state(button button, float state) {
	key_bindings[button] = state;
}

void input_set_button_pressed(button button) {

	/*
	if (button < 0 || button > INPUT_BUTTON_MAX) {
		printf("Invaid button press\n");
		return;
	}
	*/

	key_bindings[button] = true;
}

void input_set_button_released(button button) {

	//if (button < 0 || button > INPUT_BUTTON_MAX) {
	//	return;
	//}

	key_bindings[button] = false;
}

bool input_state_button(button state) {
	return key_bindings[state];
}

void input_clear_all_inputs() {
	memset(&key_bindings[0], 0, sizeof(key_bindings));
}

const char* input_button_name(button button) {
	//return button_names[button];
	return nullptr;
}


bool input_pump_events() {
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
				input_set_button_pressed(INPUT_KEY_SPACE);
				break;
			case SDLK_LEFT:
				input_set_button_pressed(INPUT_KEY_LEFT);
				break;
			case SDLK_RIGHT:
				input_set_button_pressed(INPUT_KEY_RIGHT);
				break;
			case SDLK_UP:
				input_set_button_pressed(INPUT_KEY_UP);
				break;
			case SDLK_DOWN:
				input_set_button_pressed(INPUT_KEY_DOWN);
				break;
			case SDLK_g:
				input_set_button_pressed(INPUT_KEY_G);
				break;
			case SDLK_h:
				input_set_button_pressed(INPUT_KEY_H);
				break;
			case SDLK_x:
				input_set_button_pressed(INPUT_KEY_X);
				break;
			case SDLK_z:
				input_set_button_pressed(INPUT_KEY_Z);
				break;
            case SDLK_w:
				input_set_button_pressed(INPUT_KEY_W);
				break;
            case SDLK_a:
				input_set_button_pressed(INPUT_KEY_A);
				break;
            case SDLK_s:
				input_set_button_pressed(INPUT_KEY_S);
				break;
            case SDLK_d:
				input_set_button_pressed(INPUT_KEY_D);
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
				input_set_button_released(INPUT_KEY_SPACE);
				break;
			case SDLK_LEFT:
				input_set_button_released(INPUT_KEY_LEFT);
				break;
			case SDLK_RIGHT:
				input_set_button_released(INPUT_KEY_RIGHT);
				break;
			case SDLK_UP:
				input_set_button_released(INPUT_KEY_UP);
				break;
			case SDLK_DOWN:
				input_set_button_released(INPUT_KEY_DOWN);
				break;
			case SDLK_g:
				input_set_button_released(INPUT_KEY_G);
				break;
			case SDLK_h:
				input_set_button_released(INPUT_KEY_H);
				break;
			case SDLK_x:
				input_set_button_released(INPUT_KEY_X);
				break;
			case SDLK_z:
				input_set_button_released(INPUT_KEY_Z);
				break;
            case SDLK_w:
				input_set_button_released(INPUT_KEY_W);
				break;
            case SDLK_a:
				input_set_button_released(INPUT_KEY_A);
				break;
            case SDLK_s:
				input_set_button_released(INPUT_KEY_S);
				break;
            case SDLK_d:
				input_set_button_released(INPUT_KEY_D);
				break;

			}
		}
	}
    return false;
}