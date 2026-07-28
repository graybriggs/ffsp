#pragma once

#include <array>

enum input_key_list {
	INPUT_KEY_LEFT = 0,
	INPUT_KEY_RIGHT = 1,
	INPUT_KEY_UP = 2,
	INPUT_KEY_DOWN = 3,
	INPUT_KEY_G = 4,
	INPUT_KEY_H = 5,
	INPUT_KEY_X = 6,
	INPUT_KEY_Z = 7,
	INPUT_KEY_SPACE = 8,
    INPUT_KEY_W = 10,
    INPUT_KEY_A = 11,
    INPUT_KEY_S = 12,
    INPUT_KEY_D = 13,

	INPUT_KEY_MAX = 14
};

struct mouse_coords {
	int mouse_x;
	int mouse_y;
};

struct input_data {
	input_key_list key;
	std::array<int, INPUT_KEY_MAX> key_bindings;
	
	bool mouse_left;
	bool mouse_right;
	mouse_coords coords;

	bool quit;
};

void input_init(input_data& input);

void input_set_left_mouse_click(input_data& input);
void input_set_left_mouse_release(input_data& input);
void input_set_right_mouse_click(input_data& input);
void input_set_left_mouse_release(input_data& input);
mouse_coords input_get_mouse_coords(input_data& input);

void input_set_button_state(input_data& input, float state);
void input_set_button_pressed(input_data& input, input_key_list key);
void input_set_button_release(input_data& input, input_key_list key);
bool input_query_button_state(input_data& input, input_key_list key);
void input_clear_all_inputs(input_data& input);
const char* input_button_name(input_data& key);

bool input_pump_events(input_data& input);