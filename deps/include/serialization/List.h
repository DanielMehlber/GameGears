#pragma once
#include <vector>
#include "ListNode.h"
#include "ListNode.cpp"

template<typename type> class List
{
public:
	List();
	List(type arr[], int size);
	~List();
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
	ListNode<type>* first = nullptr;

};

