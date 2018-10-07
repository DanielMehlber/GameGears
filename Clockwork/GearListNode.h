#pragma once
template<typename type> class GearListNode
{
public:
	GearListNode(type obj);
	~GearListNode();
	type content;
	GearListNode<type>* child;
	void append(type obj);
	GearListNode<type>* pull(int times_left);
	int getSizeFromHere(int size);
	int getIndexFromHere(type obj, int index);
};

