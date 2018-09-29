#pragma once
#include "Transform.h"
#include "Canvas.h"
#include "ComponentStack.h"
#include "glm/glm.hpp"


class Canvas;

class Camera :
	public Transform, public ComponentStack
{
public:
	Camera(Canvas * canvas);
	Camera(Canvas * canvas, float fov, float near, float far);
	~Camera();
	float getFOV();
	float getAspectRatio();
	float getNear();
	float getFar();
	Canvas* getCanvas();
	void setFOV(float value);
	void setAspectRatio(float value);
	void setNear(float value);
	void setFar(float value);
	void setCanvas(Canvas* canvas);
	glm::mat4 getViewProjectionMatrix();
	void setTarget(glm::vec3 target);
private:
	float fov, aspect_ratio, near, far;
	Canvas* canvas;
	glm::mat4 m_perspective;
	glm::vec3 target;
	glm::vec3 foreward;
	glm::vec3 up;

};

