#pragma once

#include <array>

enum input_key_list {
	INPUT_KEY_LEFT,
	INPUT_KEY_RIGHT,
	INPUT_KEY_UP,
	INPUT_KEY_DOWN,
	INPUT_KEY_A,
	INPUT_KEY_B,
	INPUT_KEY_C,
	INPUT_KEY_D,
 	INPUT_KEY_E,
	INPUT_KEY_F,
	INPUT_KEY_G,
	INPUT_KEY_H,
	INPUT_KEY_I,
	INPUT_KEY_J,
	INPUT_KEY_K,
	INPUT_KEY_L,
	INPUT_KEY_M,
	INPUT_KEY_N,
	INPUT_KEY_O,
	INPUT_KEY_P,
	INPUT_KEY_Q,
	INPUT_KEY_R,
	INPUT_KEY_S,
	INPUT_KEY_T,
	INPUT_KEY_U,
	INPUT_KEY_V,
	INPUT_KEY_W,
	INPUT_KEY_X,
	INPUT_KEY_Y,
	INPUT_KEY_Z,
	INPUT_KEY_1,
	INPUT_KEY_2,
	INPUT_KEY_3,
	INPUT_KEY_4,
	INPUT_KEY_5,
	INPUT_KEY_6,
	INPUT_KEY_7,
	INPUT_KEY_8,
	INPUT_KEY_9,
	INPUT_KEY_0,
	INPUT_KEY_SPACE,
	INPUT_KEY_ESCAPE,
	/// COUNT
	INPUT_KEY_COUNT
};


// const char* key_names[INPUT_KEY_COUNT] = {
// 	[INPUT_KEY_UP] = "UP",
// 	[INPUT_KEY_DOWN] = "DOWN",
// 	[INPUT_KEY_LEFT] = "LEFT",
// 	[INPUT_KEY_RIGHT] = "RIGHT",
// 	[INPUT_KEY_A] = "A",
// 	[INPUT_KEY_B] = "B",
// 	[INPUT_KEY_C] = "C",
// 	[INPUT_KEY_D] = "D",
// 	[INPUT_KEY_E] = "E",
// 	[INPUT_KEY_F] = "F",
// 	[INPUT_KEY_G] = "G",
// 	[INPUT_KEY_H] = "H",
// 	[INPUT_KEY_I] = "I",
// 	[INPUT_KEY_J] = "J",
// 	[INPUT_KEY_K] = "K",
// 	[INPUT_KEY_L] = "L",
// 	[INPUT_KEY_M] = "M",
// 	[INPUT_KEY_N] = "N",
// 	[INPUT_KEY_O] = "O",
// 	[INPUT_KEY_P] = "P",
// 	[INPUT_KEY_Q] = "Q",
// 	[INPUT_KEY_R] = "R",
// 	[INPUT_KEY_S] = "S",
// 	[INPUT_KEY_T] = "T",
// 	[INPUT_KEY_U] = "U",
// 	[INPUT_KEY_V] = "V",
// 	[INPUT_KEY_W] = "W",
// 	[INPUT_KEY_X] = "X",
// 	[INPUT_KEY_Z] = "Y",
// 	[INPUT_KEY_Z] = "Z",
// 	[INPUT_KEY_SPACE] = "SPACE"
// };

struct mouse_coords {
	int mouse_x;
	int mouse_y;
};

struct input_data {
	input_key_list key;
	std::array<int, INPUT_KEY_COUNT> key_bindings;
	
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
const char* input_button_name(input_key_list key);

bool input_pump_events(input_data& input);

bool input_quit(input_data& input);