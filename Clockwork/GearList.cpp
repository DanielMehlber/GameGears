#pragma once
#include "GearList.h"


template<typename type>
inline GearList<type>::GearList()
{
	first = nullptr;
}

template<typename type>
GearList<type>::GearList(type arr[], int size)
{
	for (int i = 0; i < size; i++) {
		append(arr[i]);
	}
}


template<typename type>
GearList<type>::~GearList()
{

}

template<typename type>
void GearList<type>::append(type obj)
{
	if (first)
		first->append(obj);
	else
		first = new GearListNode<type>(obj);
}

template<typename type>
void GearList<type>::append_once(type obj)
{
	if (find(obj) != -1)
		return;
	else
		append(obj);
}


template<typename type>
void GearList<type>::remove_at(int index)
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

	GearListNode<type>* before = first->pull(index - 1);
	GearListNode<type>* node = before->pull(1);
	GearListNode<type>* after;

	if (_size == index + 1)
		after = nullptr;
	else
		after = node->pull(1);

	before->child = after;
	node->~GearListNode();


}

template<typename type>
void GearList<type>::remove(type obj)
{
	remove_at(find(obj));
}

template<typename type>
std::vector<type> GearList<type>::getData()
{
	std::vector<type> v;
	if (!first)
		return v;
	
	for (int i = 0; i < size(); i++)
		v.push_back(get(i));

	return v;
}

template<typename type>
type GearList<type>::get(int index)
{
	if (!first)
		return NULL;
	return first->pull(index)->content;
}

template<typename type>
void GearList<type>::set(int index, type obj)
{
	if (size() < index + 1) {
		Console::err("SET_OUT_OF_BOUNDS", "Cannot set outside of bounds");
		return;
	}

	first->pull(index)->content = obj;
}

template<typename type>
int GearList<type>::find(type obj)
{
	if (first)
		return first->getIndexFromHere(obj, 0);
	else
		return -1;
}

template<typename type>
int GearList<type>::size()
{
	if (first)
		return first->getSizeFromHere(0);
	else
		return 0;
}

template<typename type>
type * GearList<type>::toArray()
{
	type* arr = new type[size()];
	for (int i = 0; i < size(); i++)
		arr[i] = get(i);
	return arr;
}

template<typename type>
void GearList<type>::clear()
{
	for (int i = 0; i < size(); i++)
		remove_at(i);
}

