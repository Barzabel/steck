#pragma once


template<class T>
Steck<T>::Steck() {




}


template<class T>
void Steck<T>::push(T item) {
	Node2<T> * push  = new Node2<T>(item);
	
	this->add_in_tail(push );



	
}




template<class T>
T Steck<T>::pop() {
	if (this->gethead() == nullptr) {
		throw std::out_of_range("index abroad");
	}

	Node2<T> *del = this->gettail();
	T pop = this->gettail()->value;
	this->deltail();

	return pop;
}

template<class T>
T Steck<T>::pop_in_head() {
	if (this->gethead() == nullptr) {
		throw std::out_of_range("index abroad");
	}
	T pop = this->gethead()->value;
	this->delhead();

	return pop;
}


template<class T>
T Steck<T>::peek() {
	if (this->gethead() == nullptr) {
		throw std::out_of_range("index abroad");
	}


	return this->gettail()->value;
}



template<class T>
unsigned int Steck<T>::Size() {


	return this->getsize();
}

