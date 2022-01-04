#pragma once
#include <iostream>

class Test2 {

private:
	double* val;
public:
	Test2(double newVal) {
		val = new double(newVal);
	}
	~Test2() {
		if (val != NULL)
			std::cout << "usuwam " << *val << "\n";
		delete val;
	}
	Test2(const Test2& other) {
		val = new double;
		*val = *other.val;
		std::cout << "kopiujacy\n";
	}
	Test2(Test2&& other)noexcept {

		val = new double;
		val = other.val;
		other.val = NULL;
		std::cout << "przenoszacy\n";
	}
	Test2& operator=(const Test2& other) {
		if (this == &other) {
			return *this;
		}
		if (val != NULL)
			delete val;
		val = new double(*other.val);

		return *this;
	}
	Test2 operator+(const Test2& other) {
		double t = *val + *other.val;
		Test2 temp(t);

		return temp;
	}
	void print() {
		if (val != NULL)
			std::cout << "[" << *val << "]\n";

	}
};