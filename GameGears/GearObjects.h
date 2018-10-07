#pragma once

enum ShaderType {
	VERTEX_SHADER,
	FRAGMENT_SHADER,
	GEOMETRY_SHADER
};

enum TagType {
	CREATE,
	PULL,
	EDIT
};

struct Tag {
	TagType type;
	const char* arg;
};

struct Gear {
	const char* name;
};

struct Transformable {
	float x, y, z, rx, ry, rz, sx, sy, sz;
};

struct Loadable {
	const char* file;
	bool valid;
};

struct GameObject : Gear, Loadable {
	Mesh* mesh;
	TexturePack* texures;
};

struct Mesh : Gear, Loadable {

};

struct TexturePack : Gear {
	Texture* diffuse;
	Texture* normal;
	Texture* specular;
	Texture* emission;
};

struct Texture : Gear, Loadable {

};

struct ShaderPack : Gear {
	Shader* vertex;
	Shader* fragment;
	Shader* geometry;
};

struct Shader : Gear, Loadable {
	ShaderType type;
};

struct Instance : Gear, Transformable {
	GameObject* reference;
};