#pragma once
#include "BehaviorComponent.h"
#include "BehaviorComponent.cpp"
#include "GameObject.h"
class ObjectBehaviorExample : public BehaviorComponent<Instance>
{
public:
	ObjectBehaviorExample();
	~ObjectBehaviorExample();

	void start(Instance* object, SyncTask* task) override;
	void update(Instance* object, SyncTask* task) override ;
	void pause(Instance* object, SyncTask* task) override;
	void destroy(Instance* object, SyncTask* task) override;

	float counter;
};

