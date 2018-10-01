#include "TaskManager.h"



TaskManager::TaskManager(unsigned int ups) : Synchronizer(ups)
{
	tasks = List<SyncTask*>();
	paused = false;
}

TaskManager::TaskManager() : TaskManager(0)
{
}


TaskManager::~TaskManager()
{
	tasks.~List();
}

void TaskManager::register_task(SyncTask * task)
{
	if (getTask(task->getName()) != nullptr) {
		std::string name = task->getName();
		std::string error = "Cannot add a Task with redundant Taskname " + name;
		Console::err("TASK-ANOMALY-ERROR", error.c_str());
		Console::leave();
	}
	tasks.append(task);
}

void TaskManager::unregister_task(SyncTask * task)
{
	tasks.remove(task);
}

void TaskManager::start()
{
	while(!terminate_all) {
		while (paused == false && terminate_all == false) {
			if (tasks.getData().size() == 0)
				//No Tasks -> The Manager will terminate itself
				terminate();

			if (Synchronizer::is_update_allowed())
				update();
				
		}
	}

	for (SyncTask* task : tasks.getData()) {
		unregister_task(task);
	}

	Console::print("TaskManager", "TERMINATED");
}

void TaskManager::start(enum TaskManager::THREADING_HINT hint) {
	switch (hint) {
	case NEW_THREAD: {
		mgr_thread = std::thread([this] {this->start(); });
		break;
	}
	case NO_THREAD: {
		this->start();
		break;
	}
	}
}

SyncTask * TaskManager::getTask(std::string name)
{
	std::vector<SyncTask*> data_vector = tasks.getData();
	for (SyncTask* task : data_vector) {

		if (task->getName() == name) {
			return task;
		}
	}

	return nullptr;
}

void TaskManager::pause()
{
	paused = true;
}

void TaskManager::terminate()
{
	terminate_all = true;
}

void TaskManager::update()
{
	for (SyncTask* task : tasks.getData()) {
		int re = task->fire();
		process_return(task, re);
	}
}

void TaskManager::process_return(SyncTask * task, int re)
{
	if (re == Task::TERMINATE)
		unregister_task(task);
}

