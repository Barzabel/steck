#pragma once





	template<class T>
	Node2<T>::Node2(T value) :next(nullptr), prev(nullptr), value( value)
	{


		
	}


	template<class T>
	T Node2<T>::getval()  {
		return this->value;
	}



