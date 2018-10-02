#include "ComponentStack.h"



ComponentStack::ComponentStack()
{
	components = List<Component*>();
}


ComponentStack::~ComponentStack()
{
}

List<Component*> ComponentStack::getTaged(Component::tags tag)
{
	List<Component*> taged = List<Component*>();
	for (Component* comp : components.getData()) {
		if (comp->tag == tag) {
			taged.append(comp);
		}
	}

	return taged;
}

