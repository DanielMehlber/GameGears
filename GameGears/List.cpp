#pragma once
#include "List.h"


template<typename type>
inline List<type>::List()
{
	first = nullptr;
}

template<typename type>
List<type>::List(type arr[], int size)
{
	for (int i = 0; i < size; i++) {
		append(arr[i]);
	}
}

template<typename type>
List<type>::List(glm::vec3 vector)
{
	append(vector.x);
	append(vector.y);
	append(vector.z);
}

template<typename type>
List<type>::~List()
{

}

template<typename type>
void List<type>::append(type obj)
{
	if (first)
		first->append(obj);
	else
		first = new ListNode<type>(obj);
}

template<typename type>
void List<type>::append_once(type obj)
{
	if (find(obj) != -1)
		return;
	else
		append(obj);
}


template<typename type>
void List<type>::remove_at(int index)
{
	if (!first)
		return;
	int _size = size();

	if (_size == 0)
		return;

	if (_size < index+1) {
		Console::err("REMOVE_OUT_OF_BOUNDS", "Cannot remove objects outside of bounds");
		return;
	}

	if (index == 0) {
		first = nullptr;
		return;
	}

	ListNode<type>* before = first->pull(index - 1);
	ListNode<type>* node = before->pull(1);
	ListNode<type>* after;

	if (_size == index + 1)
		after = nullptr;
	else
		after = node->pull(1);

	before->child = after;
	node->~ListNode();


}

template<typename type>
void List<type>::remove(type obj)
{
	remove_at(find(obj));
}

template<typename type>
std::vector<type> List<type>::getData()
{
	std::vector<type> v;
	if (!first)
		return v;
	
	for (int i = 0; i < size(); i++)
		v.push_back(get(i));

	return v;
}

template<typename type>
type List<type>::get(int index)
{
	if (!first)
		return NULL;
	return first->pull(index)->content;
}

template<typename type>
void List<type>::set(int index, type obj)
{
	if (size() < index + 1) {
		Console::err("SET_OUT_OF_BOUNDS", "Cannot set outside of bounds");
		return;
	}

	first->pull(index)->content = obj;
}

template<typename type>
int List<type>::find(type obj)
{
	if (first)
		return first->getIndexFromHere(obj, 0);
	else
		return -1;
}

template<typename type>
int List<type>::size()
{
	if (first)
		return first->getSizeFromHere(0);
	else
		return 0;
}

template<typename type>
type * List<type>::toArray()
{
	type* arr = new type[size()];
	for (int i = 0; i < size(); i++)
		arr[i] = get(i);
	return arr;
}

template<typename type>
void List<type>::clear()
{
	for (int i = 0; i < size(); i++)
		remove_at(i);
}

