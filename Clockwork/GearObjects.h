#pragma once
#include "GearList.h"
#include "GearList.cpp"


struct GearObject {
	const char* name;
};

struct GearMesh : GearObject {
	float* positions;
	float* tex_coords;
	float* normals;
};

struct GearTexture : GearObject {
	int width;
	int height;
	int channel;
	unsigned char* data;
};

struct GearTexturePack : GearObject {
	GearTexture* diffuse;
	GearTexture* normal;
	GearTexture* specular;
	GearTexture* emission;
};

struct GearGameObject : GearObject {
	GearMesh* mesh;
	GearTexturePack* textures;
};


struct Transform {
	float x, y, z, rx, ry, rz, sx, sy, sz;
};

struct GearInstance : GearObject, Transform {
	GearGameObject* reference;
};

struct GearFile {
	const char* loc;
	GearGameObject* objects;
};

