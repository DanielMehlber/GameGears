#include "TextureComponent.h"



TextureComponent::TextureComponent() : Component(Component::tags::RENDER_RELEVANT)
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
