#pragma once
#include "BehaviorComponent.h"


template <typename type> 
BehaviorComponent<type>::BehaviorComponent(const char* name) : Component(Component::tags::SCRIPTED_BEHAVIOR), SyncTask(name, &update_all_function, 60)
{
}

template <typename type>
BehaviorComponent<type>::~BehaviorComponent()
{
}

template<typename type>
void BehaviorComponent<type>::update_all(SyncTask* task)
{
	for (int i = 0; i < getUsers<type>().size(); i++) {
		type* obj = getUsers<type>().get(i);
		this->update(obj, task);
	}

}

template<typename type>
void BehaviorComponent<type>::start_all(SyncTask * task)
{
	for (type* user : *getUsers<type>()->getData()) {
		start(user, task);
	}
}

template<typename type>
void BehaviorComponent<type>::pause_all(SyncTask * task)
{
	for (type* user : *getUsers<type>()->getData()) {
		pause(user, task);
	}
}

template<typename type>
void BehaviorComponent<type>::destroy_all(SyncTask * task)
{
	for (type* user : *getUsers<type>()->getData()) {
		destroy(user, task);
	}
}





