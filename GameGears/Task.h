#pragma once
#include <functional>
#include "Console.h"
class Task
{
public:
	const static int CONTINUE = 0;
	const static int TERMINATE = -1;
	Task(std::string name, std::function<int(Task*)> action, unsigned int frame_offset);
	Task(std::string name, std::function<int(Task*)> action);
	~Task();
	virtual int fire();
	void pause();
	void resume();
	void terminate();
	bool isPaused();
	std::string getName();
	std::function<int(Task*)> action;
private:
	std::string name;
	unsigned int frame_offset;
	unsigned int frames_passed = 0;
	bool paused = false;

};

