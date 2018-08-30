#pragma once
#include "Task.h"
#include "Console.h"
#include "Synchronizer.h"
class SyncTask : public Task, public Synchronizer
{
public:
	SyncTask(std::string name, std::function<int(Task* task)> action, unsigned int fps);
	~SyncTask();
	int fire();

};


