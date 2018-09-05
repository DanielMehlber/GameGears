#include "Component.h"



Component::Component(tags tag)
{
	user_stacks = List<ComponentStack*>();
	Component::tag = tag;
}

Component::~Component()
{
}
