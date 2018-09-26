#pragma once
#include "Component.h"
#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::render()
{
	if (rendered)
		return;

	for (Instance* instance : *instances.getData()) {
		instance->spawn();
	}

	rendered = true;
}

Instance * GameObject::instance()
{
	Instance * inst = new Instance(this);
	instances.append(inst);
	return inst;
}

void GameObject::activate()
{
	if (rendered)
		return;

	MeshComponent* meshCmp = getComponent<MeshComponent>();
	ShaderComponent* shaderCmp = getComponent<ShaderComponent>();
	TextureComponent* textureCmp = getComponent<TextureComponent>();

 
	if (meshCmp == nullptr)
		return;
	if (shaderCmp == nullptr) {
		shaderCmp = ShaderComponent::genDefaultShader();
		Console::print("SHADER_GEN", "Generated default shaders");
	}
	if (textureCmp != nullptr)
		textureCmp->activate();
	meshCmp->activate();
	active = true;

}

void GameObject::deactivate()
{
	getComponent<MeshComponent>()->deactivate();
	getComponent<ShaderComponent>()->deactivate();
	getComponent<TextureComponent>()->deactivate();

	active = false;
}



