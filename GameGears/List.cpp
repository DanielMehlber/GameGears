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

}

template<typename type>
void List<type>::append_once(type obj)
{

}


template<typename type>
void List<type>::remove_at(int index)
{
	
}

template<typename type>
void List<type>::remove(type obj)
{
	remove_at(find(obj));
}

template<typename type>
std::vector<type> List<type>::getData()
{
	
}

template<typename type>
type List<type>::get(int index)
{
	
}

template<typename type>
void List<type>::set(int index, type obj)
{
	
}

template<typename type>
int List<type>::find(type obj)
{
	
}

template<typename type>
int List<type>::size()
{
	
}

template<typename type>
type * List<type>::toArray()
{
	
}

template<typename type>
void List<type>::clear()
{
	
}

