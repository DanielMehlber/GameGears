#pragma once
#include "glm/glm.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/transform.hpp"
#include <functional>
class Transform
{
public:
	Transform();
	~Transform();
	void setPos(glm::vec3);
	void setRot(glm::vec3);
	void setScale(glm::vec3);
	void setPos(float x, float y, float z);
	void setRot(float x, float y, float z);
	void setScale(float s);
	void setScale(float x, float y, float z);
	void move(float x, float y, float z);
	void rotate(float x, float y, float z);
	glm::mat4 getTransformationMatrix();
	void transformation_changed();
private:
	glm::vec3 pos;
	glm::mat4 matrix_pos;
	glm::vec3 scale;
	glm::mat4 matrix_scale;
	glm::mat4 matrix_rot_x;
	glm::mat4 matrix_rot_y;
	glm::mat4 matrix_rot_z;
	glm::vec3 rot;
	glm::mat4 transformation;

};

