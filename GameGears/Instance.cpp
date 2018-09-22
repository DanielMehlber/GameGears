#include "Instance.h"



Instance::Instance(GameObject* ref)
{
	this->reference = ref;
}


Instance::~Instance()
{
}

void Instance::render()
{
	
}

GameObject * Instance::getReferenceObject()
{
	return this->reference;
}

void Instance::activate()
{
	ShaderComponent* shaderCmp = reference->getComponent<ShaderComponent>();
	shaderCmp->uniform_transformation_matrix->set(Transform::getTransformationMatrix());
	shaderCmp->activate();
}

void Instance::deactivate()
{
}
