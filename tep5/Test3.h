#pragma once
#pragma once
#include <iostream>
#include <vector>

class Test3 {

private:
	std::vector<double*> val;
public:
	Test3(double newVal) {
		val.push_back(new double(newVal));
	}
	~Test3() {

		std::cout << "destrk\n";
		for (int i = 0; i < val.size(); i++) {
			if (val[i] != NULL) {
				std::cout << "usuwam " << *val[i] << "\n";
				delete val[i];
			}

		}
	}
	Test3(const Test3& other) {

		for (int i = 0; i < val.size(); i++) {
			*val[i] = *other.val[i];
		}
		std::cout << "kopiujacy\n";
	}
	Test3(Test3&& other)noexcept {


		val = other.val;
		for (int i = 0; i < other.val.size(); i++) {
			other.val[i] = NULL;
		}
		std::cout << "przenoszacy\n";
	}
	Test3& operator=(const Test3& other) {
		if (this == &other) {
			return *this;
		}

		val.clear();

		for (int i = 0; i < other.val.size(); i++) {
			val.push_back(new double(*other.val[i]));
		}

		return *this;
	}
	Test3 operator+(const Test3& other) {

		Test3 temp(0);
		for (int i = 0; i < val.size(); i++) {
			temp.val.push_back(new double(*val[i]));
		}
		for (int i = 0; i < other.val.size(); i++) {
			temp.val.push_back(new double(*other.val[i]));
		}

		return temp;
	}
	void print() {
		for (int i = 0; i < val.size(); i++) {
			if (val[i] != NULL)
				std::cout << "[" << *val[i] << "]\n";
		}

	}
};