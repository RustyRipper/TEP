
#include <iostream>
#include <string>
#include "CTable.h"

//using namespace std;

CTable::CTable() {
	s_name = "nazwa";
	std::cout << "\nbezp.: " << s_name << "\n";
	array = new int[array_length];
}
CTable::CTable(string sName, int iTableLen) {
	if (iTableLen <= 0) iTableLen = 3;
	s_name = sName;
	std::cout << "\nparametr: " << s_name << "\n";
	array_length = iTableLen;
	array = new int[iTableLen];
}
CTable::CTable(const CTable& pcOther) {
	s_name = pcOther.s_name + "_copy";
	array = new int[pcOther.array_length];

	for (int i = 0; i < pcOther.array_length; i++) {
		array[i] = pcOther.array[i];
	}
	std::cout << "\nkopiuj: " << s_name << "\n";
}

void CTable::vSetName(string sName) {
	s_name = sName;
}


bool CTable::bSetNewSize(int iTableLen) {
	if (iTableLen > 0) {
		int* array2;
		array2 = new int[iTableLen];
		array_length = iTableLen;
		delete[] array;
		array = array2;
		return true;
	}
	return false;
}

CTable* CTable::pcClone() {

	CTable* temp = new CTable(*this);
	return temp;

}
void CTable::v_mod_tab(CTable* pcTab, int iNewSize) {
	pcTab->bSetNewSize(iNewSize);
}
void CTable::v_mod_tab(CTable cTab, int iNewSize) {
	cTab.bSetNewSize(iNewSize);
}

string CTable::getName() {
	return s_name;
}
int* CTable::getArray() {
	return array;
}
int CTable::getLength() {
	return array_length;
}


CTable::~CTable() {
	cout << "\nusuwam: " << s_name << endl;
	delete[] array;

}







