#pragma once
#include "List.h"
#include "List.cpp"
#include "Renderable.h"
#include "Console.h"
#include "Task.h"
#include "Renderable.h"

class Camera;
class Renderable;

class RenderComponent
{
public:
	RenderComponent(Camera* cam);
	~RenderComponent();
	void register_object(Renderable* renderObject);
	void unregister_object(Renderable* renderObject);
	List<Renderable*> renderObjects;
	void render();
	Camera* getCamera();
	void setCamera(Camera* cam);

private:
	Camera* camera;
};

