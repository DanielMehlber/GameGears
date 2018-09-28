#pragma once
#include "BehaviorComponent.h"
#include "Instance.h"
class InstancedBehavior :
	public BehaviorComponent<Instance>
{
public:
	InstancedBehavior();
	~InstancedBehavior();
	std::function<void(Instance*, SyncTask*)> update_function;
};

