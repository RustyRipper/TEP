#pragma once
#include "RefCounter.h"

template <typename T>
class MySmartPointer
{
private:
	RefCounter* counter;
	T* pointer;
	
public:
	MySmartPointer(T* pcPointer);
	MySmartPointer(const MySmartPointer& pcOther);
	~MySmartPointer();
	T& operator*() { return(*pointer); }
	T* operator->() { return(pointer); }
	MySmartPointer& operator=(const MySmartPointer& cOther);
	void printCount();
}; 

template <typename T>
MySmartPointer<T>::MySmartPointer(T* otherPointer)
{
	pointer = otherPointer;
	counter = new RefCounter();
	counter->add();
}

template <typename T>
MySmartPointer<T>::MySmartPointer(const MySmartPointer& other)
{
	pointer = other.pointer;
	counter = other.counter;
	counter->add();
}

template <typename T>
MySmartPointer<T>::~MySmartPointer()
{
	
	if (counter->dec() == 0){
		
		delete pointer;
		delete counter;
		std::cout << "skasowane";
	}
	
}

template<typename T>
MySmartPointer<T>& MySmartPointer<T>::operator=(const MySmartPointer& other)
{
	if (pointer != other.pointer) {
		if (counter->dec() == 0){
		
			delete pointer;
			delete counter;
			std::cout << "skasowane";
		}
		counter = other.counter;
		pointer = other.pointer;
		counter->add();
	}
	return *this;
}

template <typename T>
void MySmartPointer<T>::printCount() {
	
	std::cout << "Mam odwolan: " << counter->get();
	std::cout <<"\n";
	
}