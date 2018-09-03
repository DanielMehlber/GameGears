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
	List<Component*> relevant = getTaged(Component::tags::RENDER_RELEVANT);

	MeshComponent* meshCmp = getComponent<MeshComponent>();
	ShaderComponent* shaderCmp = getComponent<ShaderComponent>();
	TextureComponent* textureCmp = getComponent<TextureComponent>();
	

	if (meshCmp == nullptr)
		return;
	if (shaderCmp == nullptr)
		shaderCmp = ShaderComponent::genDefaultShader();
	if (textureCmp != nullptr)
		textureCmp->activate();
	shaderCmp->activate();

	int users_rendered = meshCmp->user_rendered_count();

	if(users_rendered == 0)
		meshCmp->activate();
	
	meshCmp->render();

	if(users_rendered == meshCmp->users.size())
		meshCmp->deactivate();
	shaderCmp->deactivate();
	if (textureCmp != nullptr)
		textureCmp->deactivate();

	rendered = true;
}



