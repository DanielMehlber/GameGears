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

		const char* error_txt;

		switch (error)
		{
		case GL_INVALID_ENUM: {
			error_txt = "Invalid Enum";
			break;
		}
		case GL_INVALID_OPERATION: {
			error_txt = "Invalid Operation";
			break;
		}
		case GL_INVALID_VALUE: {
			error_txt = "Invalid Value";
			break;
		}
		default:
			error_txt = "-/";
			break;
		}

		//const unsigned char* err = gluErrorString(error);
		std::cerr << "OPENGL-ERROR: (Code " << error <<"): "<< error_txt << std::endl;
		return false;
	}
	return true;
}

void Console::clear_gl_error()
{
	//while (GL_NO_ERROR != glGetError());
}

