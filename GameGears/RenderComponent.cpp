#include "RenderComponent.h"


RenderComponent::RenderComponent()
{

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
	for (Renderable* renderObject : *renderObjects.getData())
		renderObject->reset();
	for (Renderable* renderObject : *renderObjects.getData()) {
		if (!renderObject->rendered)
			renderObject->activate();
			renderObject->render();
			renderObject->deactivate();
	}
	
}
