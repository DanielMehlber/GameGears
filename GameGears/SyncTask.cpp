#include "SyncTask.h"



SyncTask::SyncTask(std::string name, std::function<int(Task* task)> action, unsigned int fps) : Task(name, action, 0), Synchronizer(fps)
{
}


SyncTask::~SyncTask()
{
}

int SyncTask::fire()
{
	int return_value = Task::CONTINUE;

	if (is_update_allowed()) {
		try {
			return_value = Task::action(this);
		}
		catch (std::bad_function_call) {
			std::string message = "The Function of Task '" + getName() + "' cannot be called. Reason:\n";
			if (Task::action == nullptr) {
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
