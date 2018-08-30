#pragma once
#include "List.h"
#include "List.cpp"
#include "Task.h"
#include "Console.h"
#include "Synchronizer.h"
#include <thread>
class TaskManager : public Synchronizer
{
public:
	TaskManager(unsigned int ups);
	TaskManager();
	~TaskManager();
	enum THREADING_HINT {
		NO_THREAD = 0,
		NEW_THREAD = 1
	};
	void register_task(Task* task);
	void unregister_task(Task* task);
	void start();
	void start(enum THREADING_HINT);
	Task* getTask(std::string name);
	void pause();
	void terminate();
	void update();
private:
	List<Task*> tasks;
	bool paused;
	void process_return(Task* task, int re);
	bool terminate_all = false;
	std::thread mgr_thread;
};

