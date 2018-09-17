#pragma once
#include "ShaderComponent.h"
#include "MeshComponent.h"
#include "TextureComponent.h"
#include "ComponentStack.h"
#include "Transform.h"

class GameObject : public Renderable, public ComponentStack, public Transform
{
public:
	GameObject();
	~GameObject();
	void render() override;
	
private:
	void activate() override;
	void deactivate() override;
};


