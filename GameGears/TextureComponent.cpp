#include "TextureComponent.h"



TexturePack::TexturePack() : Component(Component::tags::RENDER_RELEVANT)
{
}


TexturePack::~TexturePack()
{
	diffuse->~Texture();
}

void TexturePack::setDiffuse(Texture * diff)
{
	TexturePack::diffuse = diff;
}

Texture * TexturePack::getDiffuse()
{
	return diffuse;
}

void TexturePack::activate()
{
	diffuse->activate(0);
}

void TexturePack::deactivate()
{
	diffuse->deactivate();
}
