#pragma once
#ifndef _Node2_
#define _Node2_


template<class T>
class Node2 {
public:
	
	Node2(T value);
	T value;
	Node2<T>* next;
	Node2<T>* prev;
	
	T getval() ;




private:

};
#include"Node2.ipp"

#endif // !_Node2_
