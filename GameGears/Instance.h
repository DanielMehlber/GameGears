#pragma once
#include "Transform.h"
#include "Renderable.h"
#include "ShaderComponent.h"
#include "TextureComponent.h"
#include "GameObject.h"
#include "MeshComponent.h"

class GameObject;

class Instance : public Transform, public Renderable
{
public:
	Instance(GameObject* ref);
	~Instance();
	void render() override;
	void activate() override;
	void deactivate() override;
	GameObject* getReferenceObject();
private:
	GameObject* reference;
};

