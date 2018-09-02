#pragma once
#include "List.h"
#include "List.cpp"

class GameObject;

class Component
{
public:
	Component();
	~Component();

	List<GameObject*> users;
private:
	 
};

