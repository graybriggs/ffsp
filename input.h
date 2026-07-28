#pragma once

#include <array>

enum input_key_list {
	INPUT_KEY_LEFT = 0,
	INPUT_KEY_RIGHT = 1,
	INPUT_KEY_UP = 2,
	INPUT_KEY_DOWN = 3,
	INPUT_KEY_A = 1,
	INPUT_KEY_B = 2,
	INPUT_KEY_C = 3,
	INPUT_KEY_D = 4,
 	INPUT_KEY_E = 5,
	INPUT_KEY_F = 6,
	INPUT_KEY_G = 7,
	INPUT_KEY_H = 8,
	INPUT_KEY_I = 9,
	INPUT_KEY_J = 10,
	INPUT_KEY_K = 11,
	INPUT_KEY_L = 12,
	INPUT_KEY_M = 13,
	INPUT_KEY_N = 14,
	INPUT_KEY_O = 15,
	INPUT_KEY_P = 16,
	INPUT_KEY_Q = 17,
	INPUT_KEY_R = 18,
	INPUT_KEY_S = 19,
	INPUT_KEY_T = 20,
	INPUT_KEY_U = 21,
	INPUT_KEY_V = 22,
	INPUT_KEY_W = 23,
	INPUT_KEY_X = 24,
	INPUT_KEY_Y = 25,
	INPUT_KEY_Z = 26,
	INPUT_KEY_1 = 27,
	INPUT_KEY_2 = 28,
	INPUT_KEY_3 = 29,
	INPUT_KEY_4 = 30,
	INPUT_KEY_5 = 31,
	INPUT_KEY_6 = 32,
	INPUT_KEY_7 = 33,
	INPUT_KEY_8 = 34,
	INPUT_KEY_9 = 35,
	INPUT_KEY_0 = 36,
	INPUT_KEY_SPACE = 37,
	/// END
	INPUT_KEY_MAX = 38
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