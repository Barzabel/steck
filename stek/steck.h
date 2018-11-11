#pragma once
#ifndef _STEKC_
#define _STEKC_
#include "LinkedList2/Node2.h"
#include "LinkedList2/LinkedList2.h"
using namespace std;


template<class T>
class Steck:private LinkedList2<T> {
public:

	Steck();

	void push(T item);

	

	T pop();

	T pop_in_head();



	T peek();


	unsigned int Size();


private:
	



};













#include"stakc.ipp"

#endif // !_STEKC_
