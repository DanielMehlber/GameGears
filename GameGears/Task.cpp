#include "Task.h"





Task::Task(std::string name, std::function<int(Task*)> action, unsigned int frame_offset) : name{ name }, action{ action }, frame_offset{ frame_offset }
{

}

Task::Task(std::string name, std::function<int(Task*)> action) : Task::Task(name, action, 0)
{
}

Task::~Task()
{
}

int Task::fire()
{
	int return_value = Task::CONTINUE;

	frames_passed += 1;
	if (frames_passed < frame_offset) {
		return Task::CONTINUE;
	}
	frames_passed = 0;

	try {
		return_value = Task::action(this);
	}
	catch (std::bad_function_call &e) {
		std::string message = "The function of Task '" + getName() + "' cannot be called. Reason:\n";
		if (action == nullptr) {
			message += "functionpointer is a nullptr, no function defined.\n";
		}
		else {
			message += "Unkown\n";
		}
		Console::err("TASK-NULLPTR-ERROR", message.c_str());

	}
	return return_value;
}

void Task::pause()
{
	paused = true;
}

void Task::resume()
{
	paused = false;
}

void Task::terminate()
{
	pause();
}

bool Task::isPaused()
{
	return paused;
}

std::string Task::getName()
{
	return Task::name;
}

