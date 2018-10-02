#pragma once
#include "List.h"
#include "List.cpp"


class ComponentStack;

class Component
{
public:
	enum tags {
		RENDER_RELEVANT,
		SCRIPTED_BEHAVIOR
	};

	Component(tags tag);
	virtual ~Component();
	List<ComponentStack*> user_stacks;
	tags tag;
	template <class user_type> List<user_type*> getUsers();
	
private:
	 
};

template<class user_type>
inline List<user_type*> Component::getUsers()
{
	List<user_type*> matching_users = List<user_type*>();
	user_type* possible_match;
	for (ComponentStack* stack : user_stacks.getData()) {
		if ((possible_match = dynamic_cast<user_type*>(stack))) {
			matching_users.append_once(possible_match);
		}
	}

	return matching_users;
}
