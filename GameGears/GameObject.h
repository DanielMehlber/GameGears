#pragma once
#include "ShaderComponent.h"
#include "MeshComponent.h"
#include "TextureComponent.h"
#include "ComponentStack.h"
#include "Transform.h"
#include "Instance.h"
#include "Renderable.h"
#include "RenderComponent.h"
#include "Camera.h"

class Instance;

class GameObject : public Renderable, public ComponentStack
{
public:
	GameObject(RenderComponent* context);
	~GameObject();
	void render() override;
	Instance* instance();
	
private:
	void activate() override;
	void deactivate() override;
	List<Instance*> instances;
};


