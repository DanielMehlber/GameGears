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
	counter += 0.01;
	object->setPos(sinf(counter), 0,0);
	object->rotate(0.1f, 0.01f, 0.0f);
}

void ObjectBehaviorExample::pause(GameObject * object, SyncTask * task)
{
}

void ObjectBehaviorExample::destroy(GameObject * object, SyncTask * task)
{
}
