#include "Texture.h"


Texture::Texture(Image * img)
{
	Texture::img = img;
	GLCall(glGenTextures(1, &id));
	GLCall(glBindTexture(GL_TEXTURE_2D, id));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP));
	GLCall(glGenerateMipmap(GL_TEXTURE_2D));

	if (img->data == NULL) {
		Console::err("IMGAE_DATA_NULL", "The Image Data is Null");
		Console::leave();
	}
	
	GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->data));
	
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));
	

}

Texture::~Texture()
{
	GLCall(glDeleteTextures(1, &id));
}


void Texture::setImage(Image * img)
{
	Texture::img = img;
}

void Texture::activate(int slot)
{
	GLCall(glBindTexture(GL_TEXTURE_2D, id));
	GLCall(glActiveTexture(GL_TEXTURE0 + slot));
	Texture::slot = slot;
}

void Texture::deactivate()
{
	//glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, 0);
}

