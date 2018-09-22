#include "Loader.h"



Loader::Loader()
{
}


Loader::~Loader()
{
}

MeshComponent* Loader::loadMesh(const char * location)
{
	return nullptr;
}

Shader* Loader::loadShader(Shader::TYPES type, const char* location)
{
	return new Shader(loadFile(location).c_str(), type);
}

Texture* Loader::loadTexture(const char * location)
{
	return nullptr;
}

Image* Loader::loadImage(const char * location)
{
	unsigned char* d;
	int w, h, c;
	d = stbi_load(location, &w, &h, &c, 0);

	if (!d) {
		Console::err("IMAGE_LOADER_ERROR", (std::string("Can't load Image file : ") + std::string(location)).c_str());
		Console::leave();
	}

	return new Image(d, w, h, c);
}

std::string Loader::loadFile(const char * location)
{
	std::string txt;
	std::ifstream infile;
	infile.open(location);
	if (!infile.is_open()) {
		std::string message = std::string("Cannot open file: ") + std::string(location);
		Console::err("FILE_LOADER_ERROR", message.c_str());
		Console::leave();
	}
	while (!infile.eof())
	{
		std::string line;
		getline(infile, line);
		txt = txt + "\n" + line;
	}
	infile.close();
	return txt;
}
