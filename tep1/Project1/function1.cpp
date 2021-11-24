#include "function1.h"
#include <iostream>
void v_alloc_table_add_5(int iSize) {

	int number = 5;

	if (iSize > 0) {

		int* array;
		array = new int[iSize];

		for (int i = 0; i < iSize; i++) {
			array[i] = i + number;
		}

		for (int i = 0; i < iSize; i++) {
			std::cout << array[i] << " ";
		}

		delete[] array;
	}
}

