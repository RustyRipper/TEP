#include "Max3SatProblem.h"
#include <fstream> 
#include <iostream>
#include <sstream>

using namespace std;
Max3SatProblem::Max3SatProblem()
{

}

Max3SatProblem::~Max3SatProblem()
{

	for (int i = 0; i < (int)clauses.size(); i++) {
		if (clauses.at(i) != NULL) {
			delete clauses.at(i);
		}
	}
	clauses.clear();

}

bool Max3SatProblem::load(string path)
{
	if (this == NULL) {
		return false;
	}

	fstream file;
	file.open(path, ios::in);

	if (file.good() == false) {
		cout << "File doesnt exist";
		return false;
	}
	string line;

	while (getline(file, line)) {

		string arr[AMOUNT_OF_VARIABLES_IN_THE_CLAUSE + 2];
		int i = 0;
		stringstream ssin(line);

		while (ssin.good() && i < AMOUNT_OF_VARIABLES_IN_THE_CLAUSE + 2) {
			ssin >> arr[i];
			++i;
		}

		vector<int> values;

		for (int i = 1; i < sizeof(arr) / sizeof(string) - 1; i++) {
			values.push_back(atoi(arr[i].c_str()));
		}

		clauses.push_back(new Clause(values));
	}

	file.close();
	return true;
}

double Max3SatProblem::compute(vector<bool>& solutions)
{
	if (this == NULL) {
		return 0.0;
	}
	double amountSolutions = 0;
	for (int i = 0; i < (int)clauses.size(); i++) {

		for (int j = 0; j < AMOUNT_OF_VARIABLES_IN_THE_CLAUSE; j++) {
			if (clauses.at(i)->getValue(j) < 0)
				clauses.at(i)->setFlag(j, !solutions.at(-1 * clauses.at(i)->getValue(j)));
			else clauses.at(i)->setFlag(j, solutions.at(clauses.at(i)->getValue(j)));
		}

		if (clauses.at(i)->checkClause()) {
			amountSolutions++;
		}
	}
	return (double)amountSolutions / clauses.size();
}
