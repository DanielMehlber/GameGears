#include "ObjectBehaviorExample.h"




ObjectBehaviorExample::ObjectBehaviorExample() : BehaviorComponent("beh")
{
	
}


ObjectBehaviorExample::~ObjectBehaviorExample()
{
}

void ObjectBehaviorExample::start(GameObject * object, SyncTask * task)
{
	std::cout << "start" << std::endl;
}

void ObjectBehaviorExample::update(GameObject * object, SyncTask * task)
{
	std::cout << "Update" << std::endl;
}

void ObjectBehaviorExample::pause(GameObject * object, SyncTask * task)
{
}

void ObjectBehaviorExample::destroy(GameObject * object, SyncTask * task)
{
}
