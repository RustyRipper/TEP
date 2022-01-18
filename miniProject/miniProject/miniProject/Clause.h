#pragma once
#include <vector>
using namespace std;
class Clause
{
public:
	Clause(vector<int>& values);

	int getValue(int index);
	bool getFlag(int index);

	void setValue(int index, int val);
	void setFlag(int index, bool flag);

	bool checkClause();

private:
	vector<int> values;
	vector<bool> flags;

};

