#pragma once
#include <vector>
#include "GearListNode.h"
#include "GearListNode.cpp"

template<typename type> class GearList
{
public:
	GearList();
	GearList(type arr[], int size);
	~GearList();
	void append(type obj);
	void append_once(type obj);
	void remove_at(int index);
	void remove(type obj);
	std::vector<type> getData();
	type get(int index);
	void set(int index, type obj);
	int find(type obj);
	int size();
	type* toArray();
	void clear();

private:
	GearListNode<type>* first = nullptr;

};

