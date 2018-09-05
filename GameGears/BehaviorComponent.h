#pragma once
#include "Component.h"
#include "SyncTask.h"

template <typename type>
class BehaviorComponent : public Component, public SyncTask
{
public:
	BehaviorComponent(const char* behavior_name);
	~BehaviorComponent();
	void update_all(SyncTask* task);
	void start_all(SyncTask* task);
	void pause_all(SyncTask* task);
	void destroy_all(SyncTask* task);
	virtual void start(type* object, SyncTask* task) = 0;
	virtual void update(type* object, SyncTask* task) = 0;
	virtual void destroy(type* object, SyncTask* task) = 0;
	virtual void pause(type* object, SyncTask* task) = 0;
	bool started = false;
	std::function<int(SyncTask*)> update_all_function = [=](SyncTask* task) {this->update_all(task); return CONTINUE; };
};

