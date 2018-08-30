#pragma once
#include "List.h"
#include "List.cpp"
#include "Renderable.h"
#include "Console.h"
#include "Task.h"
#include "Renderable.h"

class RenderComponent
{
public:
	RenderComponent();
	~RenderComponent();
	void register_object(Renderable* renderObject);
	void unregister_object(Renderable* renderObject);
	List<Renderable*> renderObjects;
	void render();
};

