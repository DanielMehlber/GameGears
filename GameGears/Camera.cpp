#include "Camera.h"

Camera::Camera(Canvas * canvas) : Camera(canvas, 60, 0.01, 1000)
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
