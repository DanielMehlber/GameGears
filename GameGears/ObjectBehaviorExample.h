#pragma once
#include "BehaviorComponent.h"
#include "BehaviorComponent.cpp"
#include "GameObject.h"
class ObjectBehaviorExample : public BehaviorComponent<GameObject>
{
public:
	ObjectBehaviorExample();
	~ObjectBehaviorExample();

	void start(GameObject* object, SyncTask* task) override;
	void update(GameObject* object, SyncTask* task) override ;
	void pause(GameObject* object, SyncTask* task) override;
	void destroy(GameObject* object, SyncTask* task) override;
};

