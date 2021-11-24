
#include <iostream>
#include <string>
#include "CTable.h"

//using namespace std;

CTable::CTable() {
	s_name = "nazwa";
	std::cout << "\nbezp.: " << s_name << "\n";
	array_length = DEFAULT_LENGTH;
	array = new int[array_length];
}
CTable::CTable(string sName, int iTableLen) {
	if (iTableLen <= 0) iTableLen = DEFAULT_LENGTH;
	s_name = sName;
	std::cout << "\nparametr: " << s_name << "\n";
	array_length = iTableLen;
	array = new int[iTableLen];
}
CTable::CTable(const CTable& pcOther) {
	s_name = pcOther.s_name + "_copy";
	array = new int[pcOther.array_length];
	array_length = pcOther.array_length;
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
 


void CTable::vSetValueAt(int iOffset, int iNewVal) {
	if (iOffset < 0 || iOffset >= array_length) {
		return;
	}
	array[iOffset] = iNewVal;

}
void CTable::vPrint() {
	for (int i = 0; i < array_length; i++) {
		std::cout << "[" << array[i] << "] ";
	}
	std::cout << "\n";
}





CTable CTable::operator+(CTable& pcOther){
	int newLength = array_length + pcOther.array_length;
	CTable temp(s_name + "+" + pcOther.s_name,newLength);
	for (int i = 0; i < newLength; i++) {
		if (i < array_length) {
			temp.array[i] = array[i];
		}
		else {
			temp.array[i] = pcOther.array[i - array_length];
		}
	}
	return temp;
}
//void CTable::operator=(CTable& pcOther){
//	array = pcOther.array;
//	array_length = pcOther.array_length;
//}

CTable& CTable::operator=(const CTable& pcOther) {
	if (this == &pcOther) {
		return *this;
	}
	delete[] array;
	s_name = pcOther.s_name;
	array_length = pcOther.array_length;
	array = new int[pcOther.array_length];
	for (int i = 0; i < pcOther.array_length; i++) {
		array[i] = pcOther.array[i];
	}
	return *this;
	
}

void CTable ::operator++(int) {
	int magic_number = 48;

	int* temp = new int[array_length+1];
	for (int i = 0; i < array_length; i++) {
		temp[i] = array[i];
	}
	delete[] array;

	this->array_length = array_length + 1;
	this->array= new int[array_length];

	for (int i = 0; i < array_length-1; i++) {
		array[i] = temp[i];
	}
	delete[] temp;

	array[array_length-1] = magic_number;
	
	
}

