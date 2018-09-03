#pragma once
#include "ShaderComponent.h"
#include "MeshComponent.h"
#include "TextureComponent.h"
#include "ComponentStack.h"

class GameObject : public Renderable, public ComponentStack
{
public:


	GameObject();
	~GameObject();
	void render() override;
	
private:
	
};


