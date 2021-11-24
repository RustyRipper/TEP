
#include "function2.h"
#include <iostream>

bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY) {

	if ((iSizeX <= 0) || (iSizeY <= 0)) {
		return false;
	}
	else {

		*piTable = new int* [iSizeX];

		for (int i = 0; i < iSizeX; i++) {

			(*piTable)[i] = new int[iSizeY];

		}

		(*piTable)[0][0] = 95;
		return true;

	}
}
