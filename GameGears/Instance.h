#pragma once
#include "GameObject.h"
#include "BehaviorComponent.h"
#include "ComponentStack.h"
#include "Transform.h"

class GameObject;

class Instance : public Transform, public ComponentStack
{
public:
	GameObject* reference;
	Instance(GameObject* ref);
	~Instance();
	void spawn();
	bool visible = true;
private:
};

