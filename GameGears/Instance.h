#pragma once
#include "GameObject.h"

class GameObject;

class Instance : public Transform
{
public:
	GameObject* reference;
	Instance(GameObject* ref);
	~Instance();
	void spawn();
	
private:
	bool visible = true;
};

