#pragma once
#include "Console.h"
template<typename type> class ListNode
{
public:
	ListNode(type obj);
	~ListNode();
	type content;
	ListNode<type>* child;
	void append(type obj);
	ListNode<type>* pull(int times_left);
	int getSizeFromHere(int size);
	type find(type obj);
	int indexFromHere(type obj, int index);
};

