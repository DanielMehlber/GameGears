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
	std::cout << "Update" << std::endl;
	counter += 0.01;
	object->setPos(sinf(counter), 0,0);
	object->rotate(0.1f, 0.01f, 0.0f);
	std::cout << glm::to_string(object->getTransformationMatrix()) << std::endl;
}

void ObjectBehaviorExample::pause(Instance * object, SyncTask * task)
{
}

void ObjectBehaviorExample::destroy(Instance * object, SyncTask * task)
{
}
