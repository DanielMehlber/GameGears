#include "Component.h"



Component::Component(tags tag)
{
	users = List<GameObject*>();
	Component::tag = tag;
}

Component::~Component()
{
}
