#pragma once
#include "SyncTask.h"
#include "GLFW/glfw3.h"
#include "Canvas.h"
class Input : public SyncTask
{
public:

	static enum InputMode {
		DEFAULT,
		IMPULS,
		INVERT
	};

	Input(std::string name, int key, Canvas* canvas);
	~Input();
	std::function<void(Canvas*)> call;
	List<int> inputs;
	bool triggered;
	InputMode mode = InputMode::DEFAULT;
	static bool is_pressed(Canvas* window, int key);
private:
	std::function<int(SyncTask*)> action;
	void check();
	Canvas* canvas;
};

