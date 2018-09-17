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
	shaderCmp->uniform_transformation_matrix->set(Transform::getTransformationMatrix());
	shaderCmp->activate();

	if (!meshCmp->active) {
		List<GameObject*> all_users = meshCmp->getUsers<GameObject>();
		meshCmp->activate();
		for (GameObject* user : *all_users.getData()) {
			user->render();
		}
		meshCmp->deactivate();
	}
	else {
		meshCmp->render();
	}

	shaderCmp->deactivate();
	if (textureCmp != nullptr)
		textureCmp->deactivate();

	rendered = true;
}

void GameObject::activate()
{
}

void GameObject::deactivate()
{
}



