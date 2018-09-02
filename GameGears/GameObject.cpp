#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::render()
{
	if (meshCmp == nullptr)
		return;
	if (shaderCmp == nullptr)
		shaderCmp = ShaderComponent::genDefaultShader();
	if (textureCmp != nullptr)
		textureCmp->activate();
	shaderCmp->activate();
	meshCmp->render();
	shaderCmp->deactivate();
	if (textureCmp != nullptr)
		textureCmp->deactivate();
}

void GameObject::setShaderComponent(ShaderComponent * cmp)
{
	shaderCmp = cmp;
}

void GameObject::setMeshComponent(MeshComponent * cmp)
{
	meshCmp = cmp;
}

void GameObject::setTextureComponent(TextureComponent * cmp)
{
	textureCmp = cmp;
}

