#pragma once


template<class T>
Steck<T>::Steck():head(nullptr),tail(nullptr),size(0) {




}


template<class T>
void Steck<T>::push(T item) {
	Node2<T> * push  = new Node2<T>(item);
	if (this->head == nullptr) {
		this->head = push;
		this->tail = push;
		this->head->next = nullptr;
	}
	if (this->head != nullptr) {
		push->prev = this->tail;
		this->tail->next = push;
		this->tail = push;
		this->tail->next = nullptr;
	}



	this->size++;
}





template<class T>
T Steck<T>::pop() {
	if (this->head == nullptr) {
		throw std::out_of_range("index abroad");
	}

	Node2<T> *del = this->tail;
	T pop = this->tail->value;
	if (this->head->next == nullptr) {
		this->head = nullptr;
		this->tail = nullptr;
	}
	else {
		this->tail = this->tail->prev;
		this->tail->next = nullptr;
	}
	this->size--;
	
	delete del;

	return pop;
}

template<class T>
T Steck<T>::pop_in_head() {
	if (this->head == nullptr) {
		throw std::out_of_range("index abroad");
	}


	Node2<T> *del = this->head;
	T pop = this->head->value;
	if (this->head->next == nullptr) {
		this->head = nullptr;
		this->tail = nullptr;
	}else{
	this->head = this->head->next;
	this->head->prev = nullptr;
	}
	this->size--;

	delete del;

	return pop;
}


template<class T>
T Steck<T>::peek() {
	if (this->head == nullptr) {
		throw std::out_of_range("index abroad");
	}


	return this->tail->value;
}



template<class T>
unsigned int Steck<T>::Size() {


	return this->size;
}


template<class T>
Steck<T>::~Steck() {
	Node2<T> *H = this->head;
	Node2<T> *del;
	while (H != nullptr) {
		del = H;
		
		
		H = H->next;
		delete del;
	}



}