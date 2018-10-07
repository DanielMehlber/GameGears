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

struct BlueprintObject {
	Tag tag;
	const char* name;
};


struct Transformable {
	float x, y, z, rx, ry, rz, sx, sy, sz;
};

struct Loadable {
	const char* file;
	bool valid;
};

struct GameObject : BlueprintObject, Loadable {
	GameObject* parent;
	Mesh* mesh;
	TextureComponent* texures;
};

struct Mesh : BlueprintObject, Loadable {

};

struct TextureComponent : BlueprintObject {
	Texture* diffuse;
	Texture* normal;
	Texture* specular;
	Texture* emission;
};

struct Texture : BlueprintObject, Loadable {

};

struct ShaderPack : BlueprintObject {
	Shader* vertex;
	Shader* fragment;
	Shader* geometry;
};

struct Shader : BlueprintObject, Loadable {
	ShaderType type;
};

struct Instance : BlueprintObject, Transformable {
	GameObject* reference;
};