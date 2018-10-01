#pragma once
#include "Transform.h"
#include "Canvas.h"
#include "ComponentStack.h"
#include "glm/glm.hpp"
#include "glm/gtx/string_cast.hpp"


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
	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();
	void setTarget(glm::vec3 target);
	glm::vec3 foreward = glm::vec3(0,0,1);
	glm::vec3 up = glm::vec3(0,1,0);
	bool target_stay_focused = false;

	//The inherited functions have to be overridden, because they don't move the camera the right way
	void move(float x, float y, float z);
	void rotate(float x, float y, float z);
	void setPos(glm::vec3 v);
	void setRot(glm::vec3 v);
	void move_view(glm::vec3);

private:
	float fov, aspect_ratio, near, far;
	Canvas* canvas;
	glm::vec3 target;

};

