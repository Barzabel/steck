#pragma once
#ifndef _STEKC_
#define _STEKC_
#include "Node2/Node2.h"
using namespace std;


template<class T>
class Steck {
public:

	Steck();

	void push(T item);



	T pop();

	T pop_in_head();
	T peek();


	unsigned int Size();



	~Steck();

private:
	unsigned int size;
	 Node2<T> *head;
	 Node2<T> *tail;


};













#include"stakc.ipp"

#endif // !_STEKC_
