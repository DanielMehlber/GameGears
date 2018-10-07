#pragma once
#include "Texture.h"
#include "Component.h"
class TextureComponent : public Component
{
public:
	TextureComponent();
	~TextureComponent();
	void setDiffuse(Texture* diff);
	Texture* getDiffuse();

	void activate();
	void deactivate();

private:
	Texture* diffuse;
};

