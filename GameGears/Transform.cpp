#include "Transform.h"



Transform::Transform() : pos{ glm::vec3() }, rot{ glm::vec3() }, scale{glm::vec3(1,1,1)}
{
	transformation_changed();
}

Transform::~Transform()
{
}

void Transform::setPos(glm::vec3 pos)
{
	this->pos = pos;
	transformation_changed();
}

void Transform::setRot(glm::vec3 rot)
{
	this->rot = rot;
	transformation_changed();
}

void Transform::setScale(glm::vec3 scale)
{
	this->scale = scale;
	transformation_changed();
}

void Transform::setPos(float x, float y, float z)
{
	this->setPos(glm::vec3(x,y,z));
}

void Transform::setRot(float x, float y, float z)
{
	this->setRot(glm::vec3(x, y, z));
}

void Transform::setScale(float s)
{
	this->setScale(s,s,s);
}

void Transform::setScale(float x, float y, float z)
{
	this->setScale(glm::vec3(x, y, z));
}

void Transform::move(float x, float y, float z)
{
	this->setPos(pos.x + x, pos.y + y, pos.z + z);
}

void Transform::rotate(float x, float y, float z)
{
	this->setRot(rot.x + x, rot.y + y, rot.z + z);
}

glm::mat4 Transform::getTransformationMatrix()
{
	return this->transformation;
}

void Transform::transformation_changed()
{
	matrix_pos = glm::translate(pos);
	matrix_scale = glm::scale(scale);
	matrix_rot_x = glm::rotate(rot.x, glm::vec3(1, 0, 0));
	matrix_rot_y = glm::rotate(rot.y, glm::vec3(0, 1, 0));
	matrix_rot_z = glm::rotate(rot.z, glm::vec3(0, 0, 1));
	glm::mat4 matrix_rot = matrix_rot_z * matrix_rot_y * matrix_rot_x;
	transformation = matrix_pos * matrix_rot * matrix_scale;
}

