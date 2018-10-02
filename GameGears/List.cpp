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
	if (first == nullptr) {
		first = new ListNode<type>(obj);
		return;
	}
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
	if (first == nullptr)
		return std::vector<type>();
	std::vector<type> v;
	int size = first->getSizeFromHere(0);
	for (int i = 0; i < size; i++)
		v.push_back(get(i));
	return v;
}

template<typename type>
type List<type>::get(int index)
{
	if (first == nullptr) {
		Console::err("LIST_EMPTY", "Cannot pull an element out of an empty list.");
		return NULL;
	}
	ListNode<type>* node = first->pull(index);
	if (!node)
		return NULL;
	return node->content;
}

template<typename type>
void List<type>::set(int index, type obj)
{
	if (first == nullptr) {
		Console::err("LIST_EMPTY", "Cannot set an element inside an empty list");
		return;
	}
	ListNode<type>* node = first->pull(index);
	if (!node)
		return;
	node->content = obj;
}

template<typename type>
int List<type>::find(type obj)
{
	if (first == nullptr)
		return -1;
	return first->indexFromHere(obj, 0);
}

template<typename type>
int List<type>::size()
{
	if (first == nullptr)
		return 0;
	return first->getSizeFromHere(0);
}

template<typename type>
type * List<type>::toArray()
{
	if (first == nullptr)
		return new type[0];
	type* arr = new type[first->getSizeFromHere(0)];
	for (int i = 0; i < size(); i++)
		arr[i] = get(i);
	return arr;
}

template<typename type>
void List<type>::clear()
{
	if (first == nullptr)
		return;
	for (int i = size()-1; i >= 0; i--) {
		remove_at(i);
	}
}

