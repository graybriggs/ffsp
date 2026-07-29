#include <cstring>
#include <iostream>
#include <string>

#include <SDL2/SDL.h>

#include "input.h"


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

const char* input_button_name(input_key_list key) {

	//return key_names[key];
	return nullptr;
};



bool input_pump_events(input_data& input) {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			input.quit = true;
			return true;
		}

		if (event.type == SDL_KEYDOWN) {
			//int code = event.key.keysym.scancode;
			int code = event.key.keysym.sym;

			int internal_code = code;
			//printf("%X | %d\n", code, internal_code);
			switch (code) {
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
			case SDLK_a:
				input_set_button_pressed(input, INPUT_KEY_A);
				break;
			case SDLK_b:
				input_set_button_pressed(input, INPUT_KEY_B);
				break;
			case SDLK_c:
				input_set_button_pressed(input, INPUT_KEY_C);
				break;
			case SDLK_d:
				input_set_button_pressed(input, INPUT_KEY_D);
				break;
            case SDLK_e:
				input_set_button_pressed(input, INPUT_KEY_E);
				break;
            case SDLK_f:
				input_set_button_pressed(input, INPUT_KEY_F);
				break;
            case SDLK_g:
				input_set_button_pressed(input, INPUT_KEY_G);
				break;
            case SDLK_h:
				input_set_button_pressed(input, INPUT_KEY_H);
				break;
			case SDLK_i:
				input_set_button_pressed(input, INPUT_KEY_I);
				break;
			case SDLK_j:
				input_set_button_pressed(input, INPUT_KEY_J);
				break;
			case SDLK_k:
				input_set_button_pressed(input, INPUT_KEY_K);
				break;
			case SDLK_l:
				input_set_button_pressed(input, INPUT_KEY_L);
				break;
            case SDLK_m:
				input_set_button_pressed(input, INPUT_KEY_M);
				break;
            case SDLK_n:
				input_set_button_pressed(input, INPUT_KEY_N);
				break;
            case SDLK_o:
				input_set_button_pressed(input, INPUT_KEY_O);
				break;
            case SDLK_p:
				input_set_button_pressed(input, INPUT_KEY_P);
				break;
			case SDLK_q:
				input_set_button_pressed(input, INPUT_KEY_Q);
				break;
			case SDLK_r:
				input_set_button_pressed(input, INPUT_KEY_R);
				break;
			case SDLK_s:
				input_set_button_pressed(input, INPUT_KEY_S);
				break;
			case SDLK_t:
				input_set_button_pressed(input, INPUT_KEY_T);
				break;
            case SDLK_u:
				input_set_button_pressed(input, INPUT_KEY_U);
				break;
            case SDLK_v:
				input_set_button_pressed(input, INPUT_KEY_V);
				break;
            case SDLK_w:
				input_set_button_pressed(input, INPUT_KEY_W);
				break;
            case SDLK_x:
				input_set_button_pressed(input, INPUT_KEY_X);
				break;
			case SDLK_y:
				input_set_button_pressed(input, INPUT_KEY_Y);
				break;
			case SDLK_z:
				input_set_button_pressed(input, INPUT_KEY_Z);
				break;
			case SDLK_SPACE:
				input_set_button_pressed(input, INPUT_KEY_SPACE);
				break;
			case SDLK_ESCAPE:
				input_set_button_pressed(input, INPUT_KEY_ESCAPE);
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
			case SDLK_a:
				input_set_button_release(input, INPUT_KEY_A);
				break;
			case SDLK_b:
				input_set_button_release(input, INPUT_KEY_B);
				break;
			case SDLK_c:
				input_set_button_release(input, INPUT_KEY_C);
				break;
			case SDLK_d:
				input_set_button_release(input, INPUT_KEY_D);
				break;
            case SDLK_e:
				input_set_button_release(input, INPUT_KEY_E);
				break;
            case SDLK_f:
				input_set_button_release(input, INPUT_KEY_F);
				break;
            case SDLK_g:
				input_set_button_release(input, INPUT_KEY_G);
				break;
            case SDLK_h:
				input_set_button_release(input, INPUT_KEY_H);
				break;
			case SDLK_i:
				input_set_button_release(input, INPUT_KEY_I);
				break;
			case SDLK_j:
				input_set_button_release(input, INPUT_KEY_J);
				break;
			case SDLK_k:
				input_set_button_release(input, INPUT_KEY_K);
				break;
			case SDLK_l:
				input_set_button_release(input, INPUT_KEY_L);
				break;
            case SDLK_m:
				input_set_button_release(input, INPUT_KEY_M);
				break;
            case SDLK_n:
				input_set_button_release(input, INPUT_KEY_N);
				break;
            case SDLK_o:
				input_set_button_release(input, INPUT_KEY_O);
				break;
            case SDLK_p:
				input_set_button_release(input, INPUT_KEY_P);
				break;
			case SDLK_q:
				input_set_button_release(input, INPUT_KEY_Q);
				break;
			case SDLK_r:
				input_set_button_release(input, INPUT_KEY_R);
				break;
			case SDLK_s:
				input_set_button_release(input, INPUT_KEY_S);
				break;
			case SDLK_t:
				input_set_button_release(input, INPUT_KEY_T);
				break;
            case SDLK_u:
				input_set_button_release(input, INPUT_KEY_U);
				break;
            case SDLK_v:
				input_set_button_release(input, INPUT_KEY_V);
				break;
            case SDLK_w:
				input_set_button_release(input, INPUT_KEY_W);
				break;
            case SDLK_x:
				input_set_button_release(input, INPUT_KEY_X);
				break;
			case SDLK_y:
				input_set_button_release(input, INPUT_KEY_Y);
				break;
			case SDLK_z:
				input_set_button_release(input, INPUT_KEY_Z);
				break;
			case SDLK_SPACE:
				input_set_button_release(input, INPUT_KEY_SPACE);
				break;
			case SDLK_ESCAPE:
				input_set_button_release(input, INPUT_KEY_ESCAPE);
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

bool input_quit(input_data& input) {
	if (input_query_button_state(input, INPUT_KEY_ESCAPE)) {
		return true;
	}
	return input.quit;
}