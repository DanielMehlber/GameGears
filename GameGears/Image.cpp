#include "Image.h"


Image::Image(unsigned char * data, int width, int height, int channel)
{
	Image::data = data;
	Image::width = width;
	Image::height = height;
	Image::channel = channel;
}

Image::~Image()
{
	stbi_image_free(data);
}

