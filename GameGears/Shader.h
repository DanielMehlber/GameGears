#pragma once
#include <string>
#include "GLEW/glew.h"
#include "Console.h"
#include <iostream>
#include <fstream>
class Shader
{
public:
	enum TYPES {
		VERTEX_SHADER = 0,
		FRAGMENT_SHADER = 1,
		GEOMETRY_SHADER = 2
};

	enum STATUS {
		OK = 0,
		COMPILATION_FAILED = 1
	};

	Shader(const char* src, TYPES type);
	~Shader();
	static Shader* loadShader(TYPES type ,const char* location);
	unsigned int id;
	TYPES type;
	STATUS status;

private:
	void init(TYPES type);
	void checkCompileStatus();

};

