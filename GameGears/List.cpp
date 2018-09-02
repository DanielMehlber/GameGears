#pragma once
#include "List.h"


template<typename type>
inline List<type>::List()
{
}

template<typename type>
List<type>::List(type arr[], int size)
{
	for (int i = 0; i < size; i++) {
		data.push_back(arr[i]);
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
	data.clear();
	data.~vector();
}

template<typename type>
void List<type>::append(type obj)
{
	data.push_back(obj);
}

template<typename type>
void List<type>::append_once(type obj)
{
	int index = find(obj);
	if (index != -1) {
		Console::err("REDUNDANT_OBJECT_DENIED", "List::append_once denies doubled/redundant appendance. The parameters object is already in this list");
	}

	append(obj);
}

template<typename type>
void List<type>::append(List<type>* l)
{
	for (type obj : *l->getData()) {
		append(obj);
	}
}

template<typename type>
void List<type>::remove_at(int index)
{
	data.erase(data.begin() + index);
	data.shrink_to_fit();
}

template<typename type>
void List<type>::remove(type obj)
{
	remove_at(find(obj));
}

template<typename type>
std::vector<type>* List<type>::getData()
{
	return &data;
}

template<typename type>
type List<type>::get(int index)
{
	return data[index];
}

template<typename type>
void List<type>::set(int index, type obj)
{
	data[index] = obj;
}

template<typename type>
int List<type>::find(type obj)
{
	int index = 0;
	for (type comp : data) {
		if (obj == comp)
			return index;
		index += 1;
	}
	return -1;
}

template<typename type>
int List<type>::size()
{
	return data.size();
}

template<typename type>
type * List<type>::toArray()
{
	type* arr = new type[data.size()];
	
	int index = 0;
	for (type obj : data) {
		arr[index] = obj;
		index++;
	}

	return arr;
}

template<typename type>
void List<type>::clear()
{
	data.clear();
}
