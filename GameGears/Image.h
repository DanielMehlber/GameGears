#pragma once
#include "Console.h"
#include "stb/stb_image.h"
class Image
{
public:
	Image(unsigned char* data, int width, int height, int channel);
	~Image();
	static Image* load(const char* location);
	int width, height, channel;
	unsigned char* data;
};

