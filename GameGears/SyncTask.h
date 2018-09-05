#pragma once
#include "Task.h"
#include "Console.h"
#include "Synchronizer.h"
class SyncTask : public Synchronizer
{
public:
	const static int CONTINUE = 0;
	const static int TERMINATE = -1;
	SyncTask(std::string name, std::function<int(SyncTask* task)>* action, unsigned int fps);
	~SyncTask();
	int fire();
	void pause();
	void resume();
	void terminate();
	bool isPaused();
	std::string getName();
	std::function<int(SyncTask*)>* action;
private:
	std::string name;
	bool paused = false;
};


