#pragma once
#include "GLEW/glew.h"
#include "OGLObject.h"
#include "Image.h"
#include "Console.h"
#include "stb/stb_image.h"

class Texture : public OGLObject
{
public:
	enum WRAPPING {
		REPEAT = GL_REPEAT,
		REPEAT_MIRRORED = GL_MIRRORED_REPEAT,
		CLAMP_EDGE = GL_CLAMP_TO_EDGE,
		CLAMP_BORDER = GL_CLAMP_TO_BORDER
	};
	Texture(Image* img);
	~Texture();
	static Texture* loadTexture(const char* location);
	void setImage(Image* img);
	void use(int slot);

private:
	Image* img;
};

