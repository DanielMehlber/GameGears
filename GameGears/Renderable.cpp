#include "Renderable.h"



Renderable::Renderable(RenderComponent* context)
{
	renderContext = context;
}


Renderable::~Renderable()
{
}

void Renderable::reset()
{
	rendered = false;
}
