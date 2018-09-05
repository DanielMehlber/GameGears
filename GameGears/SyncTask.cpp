#include "SyncTask.h"



SyncTask::SyncTask(std::string name, std::function<int(SyncTask* task)>* action, unsigned int fps) : Synchronizer(fps)
{
	SyncTask::name = name;
	SyncTask::action = action;
}


SyncTask::~SyncTask()
{
}

int SyncTask::fire()
{
	int return_value = Task::CONTINUE;

	if (is_update_allowed()) {
		try {
			return_value = (*action)(this);
		}
		catch (std::bad_function_call) {
			std::string message = "The Function of Task '" + getName() + "' cannot be called. Reason:\n";
			if (action == nullptr) {
				message += "The functionpointer is a nullptr, no function defined.\n";
			}
			else {
				message += "Unkown\n";
			}
			Console::err("TASK-NULLPTR-ERROR", message.c_str());

		}
	}

	return return_value;
}

void SyncTask::pause()
{
	paused = true;
}

void SyncTask::resume()
{
	paused = false;
}

void SyncTask::terminate()
{
	pause();
}

bool SyncTask::isPaused()
{
	return paused;
}

std::string SyncTask::getName()
{
	return name;
}
