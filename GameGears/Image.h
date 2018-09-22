#pragma once
#include "Console.h"
#include "stb/stb_image.h"
class Image
{
public:
	Image(unsigned char* data, int width, int height, int channel);
	~Image();
	int width, height, channel;
	unsigned char* data;
};

