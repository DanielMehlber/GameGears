#pragma once
#include "Texture.h"
#include "Component.h"
class TexturePack : public Component
{
public:
	TexturePack();
	~TexturePack();
	void setDiffuse(Texture* diff);
	Texture* getDiffuse();

	void activate();
	void deactivate();

private:
	Texture* diffuse;
};

