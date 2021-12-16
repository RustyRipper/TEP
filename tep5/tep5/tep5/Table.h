#include <iostream>
using namespace std;

#define DEFAULT_LENGTH 4;

class Table {
private:
	string name;
	int* array;
	int arrayLength;
	void moveHelp(Table& other);
public:
	Table();
	Table(string name, int arrayLength);
	Table(const Table& other);
	Table(Table&& other) noexcept;
	~Table();

	void setName(string name);
	bool setNewSize(int newArrayLength);
	string getName();
	int* getArray();
	int getLength();
	void setValueAt(int offset, int newVal);
	void print();
	
	void modTab(Table* tab, int newSize);
	void modTab(Table tab, int newSize);
	
	Table* clone();
	/*Table operator=(const Table& other);
	Table operator+(Table& other);
	void operator++(int);*/
	Table& operator=(Table&& other)noexcept;
	Table operator+(Table& other);
	


};