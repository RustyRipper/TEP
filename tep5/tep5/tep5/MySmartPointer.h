#pragma once
#include "RefCounter.h"

template <typename T>
class MySmartPointer
{
private:
	RefCounter<T>* counter;
	T* pointer;

public:
	MySmartPointer(T* pointer);
	MySmartPointer(const MySmartPointer& other);
	~MySmartPointer();
	T& operator*() { return(*pointer); }
	T* operator->() { return(pointer); }
	MySmartPointer& operator=(const MySmartPointer& other);
	void printCount();
	void printPointers();
	
};

template <typename T>
MySmartPointer<T>::MySmartPointer(T* otherPointer)
{
	pointer = otherPointer;
	counter = new RefCounter<T>();
	counter->add(otherPointer);
}

template <typename T>
MySmartPointer<T>::MySmartPointer(const MySmartPointer& other)
{
	pointer = other.pointer;
	counter = other.counter;
	counter->add(other.pointer);
}

template <typename T>
MySmartPointer<T>::~MySmartPointer()
{

	if (counter->dec() == 0) {

		delete pointer;
		delete counter;
		std::cout << "skasowane";
	}

}

template<typename T>
MySmartPointer<T>& MySmartPointer<T>::operator=(const MySmartPointer& other)
{
	if (pointer != other.pointer) {
		if (counter->dec() == 0) {

			delete pointer;
			delete counter;
			std::cout << "skasowane";
		}
		counter = other.counter;
		pointer = other.pointer;
		counter->add(other.pointer);
	}
	return *this;
}

template <typename T>
void MySmartPointer<T>::printCount() {

	std::cout << "Mam odwolan: " << counter->getCount();
	std::cout << "\n";

}
template <typename T>
void MySmartPointer<T>::printPointers() {

	std::cout << "Mam wskaznikow: " << counter->getAmountPointers();
	std::cout << "\n";
	
	

}