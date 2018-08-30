#pragma once
#include <iostream>
#include <string>
#include "GLEW/glew.h"

#define ASSERT(x) if(!(x)) __debugbreak();
#ifdef _DEBUG
#define GLCall(x) Console::clear_gl_error();\
	x;\
	ASSERT(Console::check_gl_errors());
#endif
#ifndef _DEBUG
#define GLCall(x) x;
#endif

class Console
{
public:
	Console();
	~Console();
	static void print(const char* subject, const char* txt);
	static void err(const char* subject, const char* txt);
	static void pause();
	static void leave();
	static bool check_gl_errors();
	static void clear_gl_error();
};
