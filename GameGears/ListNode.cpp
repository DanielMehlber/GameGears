#pragma once
#include "ListNode.h"


template<typename type>
ListNode<type>::ListNode(type obj)
{
	content = obj;
}

template<typename type>
ListNode<type>::~ListNode()
{
}


template<typename type>
void ListNode<type>::append(type obj)
{
	if (!child)
		child = new ListNode<type>(obj);
	else
		child->append(obj);
}


template<typename type>
ListNode<type>* ListNode<type>::pull(int left)
{
	if (left == 0)
		return this;
	else if (child)
		return child->pull(left - 1);
	else if (!child) {
		std::string message = std::string("Can't pull out of bounds by ") + std::to_string(left);
		Console::err("PULL_OUT_OF_BOUNDS", message.c_str());
		return nullptr;
	}

	return nullptr;

}

template<typename type>
int ListNode<type>::getSizeFromHere(int size)
{
	size++;
	if (!child)
		return size;
	else
		return child->getSizeFromHere(size);
}


template<typename type>
int ListNode<type>::getIndexFromHere(type obj, int index)
{

	if (obj == content)
		return index;
	else if (child)
		return child->getIndexFromHere(obj, index+1);
	return -1;

}
