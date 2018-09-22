#pragma once
#include "MeshComponent.h"
#include "Texture.h"
#include "Image.h"
#include "Shader.h"

class MeshComponent;

class Loader
{
public:
	Loader();
	~Loader();
	static MeshComponent* loadMesh(const char* location);
	static Shader* loadShader(Shader::TYPES type, const char* location);
	static Texture* loadTexture(const char* location);
	static Image* loadImage(const char* location);
	static std::string loadFile(const char* location);
};

