#pragma once
class Renderable
{
public:
	Renderable();
	~Renderable();
	virtual void render() = 0;
	enum usage {
		STATIC_DRAW,
		DYNAMIC_DRAW,
		STREAM_DRAW
	};
	bool rendered = false;
	void reset();
};

