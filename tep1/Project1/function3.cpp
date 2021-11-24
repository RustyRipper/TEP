
#include "function3.h"
#include <iostream>
bool b_dealloc_table_2_dim(int** piTable, int iSizeX, int iSizeY) {

	if (iSizeX >= 0 && iSizeY >= 0) {
		for (int i = 0; i < iSizeX; i++) {

			delete[] piTable[i];

		}
		delete[] piTable;
		return true;

	}
	return false;
}
