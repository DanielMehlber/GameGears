#include "Camera.h"

Camera::Camera(Canvas * canvas) : Camera(canvas, 60, 0.01f, 1000)
{
}

Camera::Camera(Canvas * canvas, float fov, float near , float far)
{
	this->canvas = canvas;
	this->fov = fov;
	this->aspect_ratio = canvas->getAspectRatio();
	this->near = near;
	this->far = far;
}

Camera::~Camera()
{
}

float Camera::getFOV()
{
	return fov;
}

float Camera::getAspectRatio()
{
	return aspect_ratio;
}

float Camera::getNear()
{
	return near;
}

float Camera::getFar()
{
	return far;
}

Canvas * Camera::getCanvas()
{
	return canvas;
}

void Camera::setFOV(float value)
{
	fov = value;
}

void Camera::setAspectRatio(float value)
{
	aspect_ratio = value;
}

void Camera::setNear(float value)
{
	near = value;
}

void Camera::setFar(float value)
{
	far = value;
}

void Camera::setCanvas(Canvas * canvas)
{
	aspect_ratio = canvas->getAspectRatio();
}

glm::mat4 Camera::getViewProjectionMatrix()
{
	return getProjectionMatrix() * getViewMatrix();
}

glm::mat4 Camera::getProjectionMatrix()
{
	return glm::perspective(glm::radians(fov), aspect_ratio, near, far);

}

glm::mat4 Camera::getViewMatrix()
{
	return glm::lookAt(getPos(), target, up);
}

void Camera::setTarget(glm::vec3 target)
{
	this->target = target;
}

void Camera::move(float x, float y, float z)
{
	setPos(glm::vec3(pos.x + x, pos.y + y, pos.z + z));
	target += glm::vec3(x, y, z);
}

void Camera::rotate(float x, float y, float z)
{
	setRot(glm::vec3(rot.x + x, rot.y + y, rot.z + z));
}

void Camera::setPos(glm::vec3 v)
{
	Transform::pos += v;
	if (!target_stay_focused) {
		target += v;
	}
}

void Camera::setRot(glm::vec3 v)
{
	if (target_stay_focused)
		return;
	Transform::rot = v;
	
}

void Camera::move_view(glm::vec3)
{
	glm::vec3 delta = target - getPos();
	foreward = glm::normalize(delta);
}
