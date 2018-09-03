#pragma once
#include "List.h"
#include "List.cpp"

class GameObject;

class Component
{
public:
	enum tags {
		RENDER_RELEVANT
	};

	Component(tags tag);
	virtual ~Component();
	List<GameObject*> users;
	tags tag;
	
private:
	 
};

