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

Image * Image::load(const char * location)
{
	unsigned char* d;
	int w, h, c;
	d = stbi_load(location, &w, &h, &c, 0);

	if (!d) {
		Console::err("IMAGE_LOADER_ERROR", (std::string("Can't load Image file : ")+std::string(location)).c_str());
		Console::leave();
	}

	return new Image(d, w, h, c);
}
