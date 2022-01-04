#include "Clause.h"

Clause::Clause(vector<int> &values)
{
	
	for (int i = 0; i < values.size(); i++) {
		this->values.push_back(values.at(i));
		flags.push_back(false);
	}
}

int Clause::getValue(int index)
{
	return values.at(index);
}

bool Clause::getFlag(int index)
{
	return flags.at(index);;
}

void Clause::setValue(int index, int val)
{
	values.at(index) = val;
}

void Clause::setFlag(int index, bool flag)
{
	flags.at(index) = flag;
}

bool Clause::checkClause()
{
	for (int i = 0; i < flags.size(); i++) {
		if (flags.at(i)) {
			return true;
		}
	}
	return false;
}
