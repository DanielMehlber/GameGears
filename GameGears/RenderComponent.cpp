#include "RenderComponent.h"


RenderComponent::RenderComponent(Camera* cam)
{
	camera = cam;
	glEnable(GL_DEPTH_TEST);
}



RenderComponent::~RenderComponent()
{
}

void RenderComponent::register_object(Renderable * renderObject)
{
	renderObjects.append_once(renderObject);
}

void RenderComponent::unregister_object(Renderable * renderObject)
{
	renderObjects.remove(renderObject);
}

void RenderComponent::render()
{
	for (Renderable* renderObject : renderObjects.getData())
		renderObject->reset();
	for (Renderable* renderObject : renderObjects.getData()) {
		if (!renderObject->rendered)
			renderObject->activate();
			renderObject->render();
			renderObject->deactivate();
	}
	
}

Camera * RenderComponent::getCamera()
{
	return camera;
}

void RenderComponent::setCamera(Camera * cam)
{
	camera = cam;
}
