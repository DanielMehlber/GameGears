#include "Console.h"



Console::Console()
{
}


Console::~Console()
{
}

void Console::print(const char* from, const char* txt)
{
	std::cout << from << ": " << txt << std::endl;
}

void Console::err(const char* from, const char* txt)
{
	std::cerr << "ERROR ("<< from <<"): " << txt << std::endl;
}

void Console::pause()
{
	std::system("pause");
}

void Console::leave()
{
	pause();
	std::exit(-1);
}

bool Console::check_gl_errors()
{
	while (GLenum error = glGetError()) {
		std::cerr << "OPENGL-ERROR: " << error << std::endl;
		return false;
	}
	return true;
}

void Console::clear_gl_error()
{
	while (GLenum error = glGetError());
}

