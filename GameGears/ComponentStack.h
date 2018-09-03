#pragma once
#include "List.h"
#include "List.cpp"
#include "Component.h"

class ComponentStack
{
public:
	ComponentStack();
	virtual ~ComponentStack();

	List<Component*> components;
	template <class type> void set(Component* comp);
	template <class type> bool has_component();
	template <class type> type* getComponent();
	List<Component*> getTaged(Component::tags tag);
	template <class type> Component* getComponentObject();
	template <typename owner_type> owner_type* getOwner();
};

template<class type>
inline void ComponentStack::set(Component * comp)
{
	comp->users::append_once(this);
	Component* cmp_object = getComponentObject<type>();
	if (cmp_object == nullptr) {
		components.append_once(comp);
		return;
	}

	components.set(components.find(cmp_object), comp);
}

template<class type>
inline bool ComponentStack::has_component()
{
	for (Component* comp : components.getData()) {
		if (dynamic_cast<type*>(comp)) {
			return true;
		}
	}

	return false;
}

template<class type>
inline type * ComponentStack::getComponent()
{
	Component* comp = getComponentObject<type>();
	type* derived_comp = dynamic_cast<type*>(comp);
	return derived_comp;
}

template<class type>
inline Component * ComponentStack::getComponentObject()
{
	for (Component* comp : *components.getData()) {
		if (dynamic_cast<type*>(comp)) {
			return comp;
		}
	}

	return nullptr;
}

template<typename owner_type>
inline owner_type * ComponentStack::getOwner()
{
	owner_type* owner = dynamic_cast<owner_type*>(this);
	return owner;
}
