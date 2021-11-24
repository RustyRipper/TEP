
using namespace std;

class CTable {
private:
	string s_name;
	int* array;
	int array_length = 3;

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


};