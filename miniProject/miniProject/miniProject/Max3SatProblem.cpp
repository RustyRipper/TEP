#include "Max3SatProblem.h"
#include <fstream> 
#include <iostream>
#include <sstream>

using namespace std;
Max3SatProblem::Max3SatProblem()
{
	
}

bool Max3SatProblem::load(string path)
{
	fstream file;
	file.open(path, ios::in);
	if (file.good() == false) {
		cout << "File doesnt exist";
		exit(0);
	}
	string line;

	while (getline(file, line)) {
		
		string arr[AMOUNT_OF_VARIABLES_IN_THE_CLAUSE+2];
		int i = 0;
		stringstream ssin(line);
		while (ssin.good() && i < AMOUNT_OF_VARIABLES_IN_THE_CLAUSE + 2) {
			ssin >> arr[i];
			++i;
		}
		vector<int> values;
		for (int i = 1; i < sizeof(arr)/sizeof(string) - 1; i++) {
			values.push_back(atoi(arr[i].c_str()));
		}
		Clause* clause= new Clause(values);
		clauses.push_back(clause);
	}
	file.close();
	return 0;

}

double Max3SatProblem::compute(vector<bool> solutions)
{
	double amountSolutions = 0;
	for (int i = 0; i < clauses.size(); i++) {

		for (int j = 0; j < AMOUNT_OF_VARIABLES_IN_THE_CLAUSE; j++) {
			if (clauses.at(i)->getValue(j) < 0)
				clauses.at(i)->setFlag(j,!solutions.at(-1 * clauses.at(i)->getValue(j)));
			else clauses.at(i)->setFlag(j,solutions.at(clauses.at(i)->getValue(j)));
		}

		if (clauses.at(i)->checkClause()) {
			amountSolutions++;
		}
	}
    return amountSolutions/clauses.size();
}
