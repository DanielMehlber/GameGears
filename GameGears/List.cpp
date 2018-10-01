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
		first->append(arr[i]);
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
	first->append(obj);
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
void List<type>::remove_at(int index)
{
	if (index > size()-1 || first == nullptr) {
		Console::err("LIST_OUT_OF_BOUNDS", "Cannot remove out of bounds");
		return;
	}

	if (index == 0) {
		first = nullptr;
		return;
	}

	ListNode<type>* before = first->pull(index - 1);
	ListNode<type>* node = before->pull(1);
	
	if (index + 1 == size()) {
		before->child = nullptr;
		node->~ListNode();
		return;
	}

	ListNode<type>* after = node->pull(1);

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
	int size = first->getSizeFromHere(0);
	for (int i = 0; i < size; i++)
		v.push_back(get(i));
	return v;
}

template<typename type>
type List<type>::get(int index)
{
	ListNode<type>* node = first->pull(index);
	if (!node)
		return NULL;
	return node->content;
}

template<typename type>
void List<type>::set(int index, type obj)
{
	ListNode<type>* node = first->pull(index);
	if (!node)
		return;
	node->content = obj;
}

template<typename type>
int List<type>::find(type obj)
{
	return first->indexFromHere(obj, 0);
}

template<typename type>
int List<type>::size()
{
	return first->getSizeFromHere(0);
}

template<typename type>
type * List<type>::toArray()
{
	type* arr = new type[first->getSizeFromHere(0)];
	for (int i = 0; i < size(); i++)
		arr[i] = get(i);
	return arr;
}

template<typename type>
void List<type>::clear()
{
	for (int i = size()-1; i >= 0; i--) {
		remove_at(i);
	}
}

