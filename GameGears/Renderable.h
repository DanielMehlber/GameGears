#pragma once
class Renderable
{
public:
	//gives a hint to the render function
	enum rendermode {
		NORMAL, //Normal render Call
		MESH_TRACE  //The Mesh is already bound, just attach components (except mesh) and render
	};

	Renderable();
	~Renderable();
	virtual void activate() = 0;
	virtual void render() = 0;
	virtual void deactivate() = 0;
	enum usage {
		STATIC_DRAW,
		DYNAMIC_DRAW,
		STREAM_DRAW
	};
	bool rendered = false;
	bool active = false;
	void reset();
};

