#include "Instance.h"




Instance::Instance(GameObject * ref)
{
	if (ref == nullptr) {
		Console::err("INVALID_INSTANCE_REFERENCE", "The reference of an instance is invalid");
	}
	Instance::reference = ref;
}

Instance::~Instance()
{
}

void Instance::spawn()
{
	//Check valid rendering context
	if (!visible)
		Console::print("","Instance invisible");
		return;
	if (reference == nullptr) {
		Console::err("INVALID_INSTANCE_REFERENCE", "The reference of an instance is invalid");
		return;
	}
	if (!reference->active) {
		Console::err("INVALID_INSTANCE_REFERANCE_STATE", "An Instances referenced GameObject is has not been activated.");
		return;
	}

	//Set Transformation Matrix
	ShaderComponent * shader = reference->getComponent<ShaderComponent>();
	shader->uniform_transformation_matrix->set(getTransformationMatrix());

	//Render instance
	reference->getComponent<MeshComponent>()->render();

}
