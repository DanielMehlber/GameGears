#pragma once
#include "Component.h"
#include "GameObject.h"



GameObject::GameObject(RenderComponent* context) : Renderable(context)
{
}


GameObject::~GameObject()
{
}

void GameObject::render()
{
	if (rendered)
		return;

	for (Instance* instance : instances.getData()) {
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
	shaderCmp->activate();
	shaderCmp->uniform_projection_matrix->set(Renderable::renderContext->getCamera()->getProjectionMatrix());
	shaderCmp->uniform_view_matrix->set(Renderable::renderContext->getCamera()->getViewMatrix());
	
	active = true;

}

void GameObject::deactivate()
{
	getComponent<MeshComponent>()->deactivate();
	getComponent<ShaderComponent>()->deactivate();
	getComponent<TextureComponent>()->deactivate();

	active = false;
}



