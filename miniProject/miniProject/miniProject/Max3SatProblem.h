#pragma once
#include "Clause.h"
#include <string>
#define AMOUNT_OF_VARIABLES_IN_THE_CLAUSE 3
#define AMOUNT_OF_VARIABLES 100
using namespace std;

class Max3SatProblem {
public:
	Max3SatProblem();
	~Max3SatProblem();
	bool load(string path);
	double compute(vector<bool>& solutions);

private:
	vector<Clause*> clauses;

};