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
	if (child == nullptr)
		child = new ListNode(obj);
	else
		child->append(obj);
}


template<typename type>
ListNode<type>* ListNode<type>::pull(int times_left)
{
	if (times_left == 0)
		return this;
	else if (child != nullptr)
		return child->pull(times_left - 1);
	else if (child == nullptr) {
		Console::err("LIST_PULL_OUT_OF_BOUNDS", "Index out of bounds");
		return nullptr;
	}
}

template<typename type>
int ListNode<type>::getSizeFromHere(int size)
{
	size++;
	if (child == nullptr)
		return size;
	else
		return child->getSizeFromHere(size);
}

template<typename type>
type ListNode<type>::find(type obj)
{
	if (content == obj)
		return content;
	else if (child == nullptr)
		return nullptr;
	else if (child != nullptr)
		return child->find(obj);
}

template<typename type>
int ListNode<type>::indexFromHere(type obj, int index)
{
	index++;
	if (obj == content)
		return index;
	else if (child == nullptr)
		return -1;
	else if (child != nullptr)
		return child->indexFromHere(obj, index);
}
