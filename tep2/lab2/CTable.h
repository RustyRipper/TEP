#include <iostream>
using namespace std;

const int DEFAULT_LENGTH = 4;
class CTable {
private:
	string s_name;
	int* array;
	int array_length;

public:
	CTable();
	CTable(string sName, int iTableLen);
	CTable(const CTable& pcOther);
	void vSetName(string sName);
	bool bSetNewSize(int iTableLen);
	CTable* pcClone();
	void v_mod_tab(CTable* pcTab, int iNewSize);
	void v_mod_tab(CTable pcTab, int iNewSize);
	string getName();
	int* getArray();
	int getLength();
	~CTable();
	//void operator=(CTable& pcOther);
	CTable& operator=(const CTable& pcOther);
	CTable operator+(CTable& pcOther);
	void operator++(int);
	void vSetValueAt(int iOffset, int iNewVal);
	void vPrint();
	

};