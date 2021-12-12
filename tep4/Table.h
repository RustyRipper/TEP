#pragma once

#include <string>
using namespace std;

template< typename T > class Table
{
public:
	Table() { size = 0; table = NULL; }
	~Table() { if (table != NULL) delete[] table; }
	bool setLength(int iNewSize);
	T* getElement(int iOffset);
	bool setElement(int iOffset, T val);
	string getKnownType();
private:
	int size;
	T* table;
};

template <typename T>
bool Table<T>::setLength(int newSize)
{
	if (newSize <= 0) return(false);
	T* newTable;
	newTable = new T[newSize];
	if (table != NULL)
	{
		int minLen;
		if (newSize < size)
			minLen = newSize;
		else
			minLen = size;
		for (int i = 0; i < minLen; i++)
			newTable[i] = table[i];
		delete[] table;
	}
	table = newTable;
	return(true);
}
template <typename T>
T* Table<T>::getElement(int offset)
{
	if ((0 <= offset) && (offset < size)) return(NULL);
	return(&(table[offset]));
}

template <typename T>
bool Table<T>::setElement(int offset, T val)
{
	if ((0 <= offset) && (offset < size)) return(false);
	table[offset] = val;
	return(true);
}

template <typename T>
string Table<T>::getKnownType()
{
	string type = "Unknown";
	return(type);
}
template <>
string Table<int>::getKnownType()
{
	string type = "INT";
	return(type);
}