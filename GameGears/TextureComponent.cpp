#include "TextureComponent.h"



TextureComponent::TextureComponent()
{
}


TextureComponent::~TextureComponent()
{
	diffuse->~Texture();
}

void TextureComponent::setDiffuse(Texture * diff)
{
	TextureComponent::diffuse = diff;
}

Texture * TextureComponent::getDiffuse()
{
	return diffuse;
}

void TextureComponent::activate()
{
	diffuse->activate(0);
}

void TextureComponent::deactivate()
{
	diffuse->deactivate();
}
