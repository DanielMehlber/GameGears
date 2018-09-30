#include "ObjectBehaviorExample.h"
#include "glm/gtx/string_cast.hpp"



ObjectBehaviorExample::ObjectBehaviorExample() : BehaviorComponent("beh")
{
	
}


ObjectBehaviorExample::~ObjectBehaviorExample()
{
}


void ObjectBehaviorExample::start(Instance * object, SyncTask * task)
{
	std::cout << "start" << std::endl;
}

void ObjectBehaviorExample::update(Instance * object, SyncTask * task)
{
	counter += 0.01f;
	object->setPos(sinf(counter), 0, sinf(counter) * 5 - 5);
	object->rotate(0.1f, 0.01f, -0.1f);

}

void ObjectBehaviorExample::pause(Instance * object, SyncTask * task)
{
}

void ObjectBehaviorExample::destroy(Instance * object, SyncTask * task)
{
}
