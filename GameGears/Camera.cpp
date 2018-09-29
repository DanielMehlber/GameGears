#include "Camera.h"

Camera::Camera(Canvas * canvas) : Camera(canvas, 70, 0.1, 100)
{
}

Camera::Camera(Canvas * canvas, float fov, float near , float far)
{
	this->canvas = canvas;
	this->fov = fov;
	this->aspect_ratio = canvas->getAspectRatio();
	this->near = near;
	this->far = far;
	this->m_perspective = glm::perspective<float>(fov, aspect_ratio, near, far);
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
	this->m_perspective = glm::perspective<float>(fov, aspect_ratio, near, far);
}

void Camera::setAspectRatio(float value)
{
	aspect_ratio = value;
	this->m_perspective = glm::perspective<float>(fov, aspect_ratio, near, far);
}

void Camera::setNear(float value)
{
	near = value;
	this->m_perspective = glm::perspective<float>(fov, aspect_ratio, near, far);
}

void Camera::setFar(float value)
{
	far = value;
	this->m_perspective = glm::perspective<float>(fov, aspect_ratio, near, far);
}

void Camera::setCanvas(Canvas * canvas)
{
}

glm::mat4 Camera::getViewProjectionMatrix()
{
	return m_perspective * glm::lookAt(Transform::getPos(), target, up);
}

void Camera::setTarget(glm::vec3 target)
{
	this->target = target;
}
