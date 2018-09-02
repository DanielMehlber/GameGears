#pragma once
#include "ShaderComponent.h"
#include "MeshComponent.h"
#include "TextureComponent.h"

class GameObject : public Renderable
{
public:


	GameObject();
	~GameObject();
	void render() override;
	void setShaderComponent(ShaderComponent* cmp);
	void setMeshComponent(MeshComponent* cmp);
	void setTextureComponent(TextureComponent* cmp);
private:
	ShaderComponent* shaderCmp;
	TextureComponent* textureCmp;
	MeshComponent* meshCmp;
};


