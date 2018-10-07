#pragma once
#include "GearListNode.h"


template<typename type>
GearListNode<type>::GearListNode(type obj)
{
	content = obj;
}

template<typename type>
GearListNode<type>::~GearListNode()
{
}


template<typename type>
void GearListNode<type>::append(type obj)
{
	if (!child)
		child = new GearListNode<type>(obj);
	else
		child->append(obj);
}


template<typename type>
GearListNode<type>* GearListNode<type>::pull(int left)
{
	if (left == 0)
		return this;
	else if (child)
		return child->pull(left - 1);
	else if (!child) {
		std::cout << "Out of Bounds" << std::endl;
		return nullptr;
	}

	return nullptr;

}

template<typename type>
int GearListNode<type>::getSizeFromHere(int size)
{
	size++;
	if (!child)
		return size;
	else
		return child->getSizeFromHere(size);
}


template<typename type>
int GearListNode<type>::getIndexFromHere(type obj, int index)
{

	if (obj == content)
		return index;
	else if (child)
		return child->getIndexFromHere(obj, index+1);
	return -1;

}
