#include "Clause.h"
#include <iostream>

Clause::Clause(vector<int>& values)
{
	for (int i = 0; i < values.size(); i++) {
		this->values.push_back(values.at(i));
		flags.push_back(false);
	}
}

int Clause::getValue(int index)
{
	if (index >= 0 && index < values.size()) {
		return values.at(index);
	}
	std::cout << "zly index Clause::getValue" << endl;
	return 0;
}

bool Clause::getFlag(int index)
{
	if (index >= 0 && index < flags.size()) {
		return flags.at(index);;
	}
	std::cout << "zly index Clause::getFlag" << endl;
	return false;
}

void Clause::setValue(int index, int val)
{
	if (index >= 0 && index < values.size()) {
		values.at(index) = val;
	}
	else {
		std::cout << "zly index Clause::setValue" << endl;
	}
}

void Clause::setFlag(int index, bool flag)
{
	if (index >= 0 && index < flags.size()) {
		flags.at(index) = flag;
	}
	else {
		std::cout << "zly index Clause::setFlag" << endl;
	}

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
