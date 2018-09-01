#pragma once
#include <string>
#include "GLEW/glew.h"
#include "Console.h"
#include <iostream>
#include <fstream>
#include "OGLObject.h"

class Shader : public OGLObject
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
	
	TYPES type;
	STATUS status;


	Shader(const char* src, TYPES type);
	~Shader();
	static Shader* loadShader(TYPES type ,const char* location);

private:
	void init(TYPES type);
	void checkCompileStatus();

};

