
#include <iostream>
#include <string>
#include "Table.h"

//using namespace std;

Table::Table() {
	name = "nazwa";
	std::cout << "\nbezp.: " << name << "\n";
	arrayLength = DEFAULT_LENGTH;
	array = new int[arrayLength];
}
Table::Table(string newName, int newArrayLength) {
	if (newArrayLength <= 0) newArrayLength = DEFAULT_LENGTH;
	name = newName;
	std::cout << "\nparametr: " << name << "\n";
	arrayLength = newArrayLength;
	array = new int[newArrayLength];
}
Table::Table(const Table& other) {
	name = other.name + "_copy";
	array = new int[other.arrayLength];
	arrayLength = other.arrayLength;
	for (int i = 0; i < other.arrayLength; i++) {
		array[i] = other.array[i];
	}
	std::cout << "\nkopiuj: " << name << "\n";
}

Table::Table(Table&& other) noexcept
{
	name = other.name + "cMove";
	moveHelp(other);
	cout << "MoveConstructor " << name << "\n";
}

Table::~Table() {
	cout << "\nusuwam: " << name << endl;
	delete[] array;
}

void Table::setName(string newName) {
	name = newName;
}
bool Table::setNewSize(int newArrayLength) {
	if (newArrayLength > 0) {
		int* array2;
		array2 = new int[newArrayLength];
		arrayLength = newArrayLength;
		delete[] array;
		array = array2;
		return true;
	}
	return false;
}
string Table::getName() {
	return name;
}
int* Table::getArray() {
	return array;
}
int Table::getLength() {
	return arrayLength;
}
void Table::setValueAt(int offset, int newVal) {
	if (offset < 0 || offset >= arrayLength) {
		return;
	}
	array[offset] = newVal;

}
void Table::print() {
	cout << name << "\n";
	for (int i = 0; i < arrayLength; i++) {
		std::cout << "[" << array[i] << "] ";
	}
	std::cout << "\n";
}

void Table::modTab(Table* tab, int newSize) {
	tab->setNewSize(newSize);
}
void Table::modTab(Table cTab, int iNewSize) {
	cTab.setNewSize(iNewSize);
}

Table* Table::clone() {

	Table* temp = new Table(*this);
	return temp;

}

Table& Table::operator=(const Table& other) {
	std::cout << "operator=& " << "\n";
	if (this == &other) {
		return *this;
	}
	delete[] array;
	name = other.name;
	arrayLength = other.arrayLength;
	array = new int[other.arrayLength];
	for (int i = 0; i < other.arrayLength; i++) {
		array[i] = other.array[i];
	}
	return *this;

}

//void Table ::operator++(int) {
//	int number = 48;
//
//	int* temp = new int[arrayLength + 1];
//	for (int i = 0; i < arrayLength; i++) {
//		temp[i] = array[i];
//	}
//	delete[] array;
//
//	this->arrayLength = arrayLength + 1;
//	this->array = new int[arrayLength];
//
//	for (int i = 0; i < arrayLength - 1; i++) {
//		array[i] = temp[i];
//	}
//	delete[] temp;
//
//	array[arrayLength - 1] = number;
//
//
//}

Table& Table::operator=(Table&& other) noexcept
{
	std::cout << "operator=&& " << "\n";
	if (array != NULL)
		delete[] array;

	moveHelp(other);
	return *this;
}



Table Table::operator+(Table& other) {

	int newLength = arrayLength + other.arrayLength;
	Table temp(name + "+move+" + other.name, newLength);

	for (int i = 0; i < newLength; i++) {
		if (i < arrayLength) {
			temp.array[i] = array[i];
		}
		else {
			temp.array[i] = other.array[i - arrayLength];
		}
	}
	return temp;
}

Table Table ::operator++(int) {
	int number = 48;

	Table t(name + "++", arrayLength + 1);
	int* temp = new int[arrayLength + 1];

	for (int i = 0; i < arrayLength; i++) {
		temp[i] = array[i];
	}
	delete[] array;

	arrayLength = arrayLength + 1;
	array = new int[arrayLength];

	for (int i = 0; i < arrayLength - 1; i++) {
		t.array[i] = temp[i];
		array[i] = temp[i];
	}
	delete[] temp;

	t.array[arrayLength - 1] = number;
	array[arrayLength - 1] = number;

	return t;
}

void Table::moveHelp(Table& other)
{
	array = other.array;
	arrayLength = other.arrayLength;
	other.array = NULL;
	other.arrayLength = 0;
}