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
	template <class type> void setComponent(type* cmp);
private:
	ShaderComponent* shaderCmp;
	TextureComponent* textureCmp;
	MeshComponent* meshCmp;
};

template<class type>
inline void GameObject::setComponent(type* cmp)
{
	bool nullset = (cmp == nullptr);

	const char* type_n = typeid(type).name();

	const char* MeshComponent_ = typeid(MeshComponent).name();
	const char* ShaderComponent_ = typeid(ShaderComponent).name();
	const char* TextureComponent_ = typeid(TextureComponent).name();

	if (type_n == MeshComponent_) {
		if(meshCmp != nullptr)
			meshCmp->users.remove(this);
		meshCmp = (MeshComponent*)cmp;
		if(!nullset)
			meshCmp->users.append_once(this);
	}
	else if (type_n == ShaderComponent_) {
		if(shaderCmp != nullptr)
			shaderCmp->users.remove(this);
		shaderCmp = (ShaderComponent*)cmp;
		if(!nullset)
			shaderCmp->users.append_once(this);
	}
	else if (type_n == TextureComponent_) {
		if(textureCmp != nullptr)
			textureCmp->users.remove(this);
		textureCmp = (TextureComponent*)cmp;
		if(!nullset)
			textureCmp->users.append_once(this);
	}


	else {
		std::string message = std::string("The GameObject has no component of type: ") + std::string(typeid(type).name());
		Console::err("INVALID_COMPONENT", message.c_str());
		Console::leave();
	}
}

