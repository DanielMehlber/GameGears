#include "Input.h"



Input::Input(std::string name, int key, Canvas* canvas) : SyncTask(name, &action, 60)
{
	action = [=](SyncTask* task) {check();  return CONTINUE; };
	inputs = List<int>();
	inputs.append(key);
	this->canvas = canvas;
	this->call = [=](Canvas* canvas) {Console::print((std::string("Input~") + name).c_str(), "KEY PRESSED"); };
}


Input::~Input()
{
}

bool Input::is_pressed(Canvas* window, int key)
{
	return glfwGetKey(window->window, key) == GLFW_PRESS;
}

void Input::check()
{
	for (int k : *inputs.getData()) {
		bool pressed = glfwGetKey(canvas->window, k) == GLFW_PRESS;
		if (mode == DEFAULT) {
			if (pressed) {
				call(canvas);
				triggered = true;
			}
			else {
				triggered = false;
			}
		}
		if (mode == INVERT) {
			if (pressed) {
				triggered = false;
			}
			else {
				call(canvas);
				triggered = true;
			}
		}
		if (mode == IMPULS) {
			if (pressed) {
				if (triggered == false) {
					call(canvas);
					triggered = true;
				}
			}
			else {
				triggered = false;
			}
		}
	}
}
