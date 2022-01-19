#include <fstream> 
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>

#include "GAOptimizer.h"

using namespace std;

int main()
{
	int amountOfIteration = 1000;
	int populationSize = 500;
	double probabilityOfCrossover = 0.4;
	double probabilityOfMutation = 0.2;

	Max3SatProblem* m3SP = new Max3SatProblem();

	string s = to_string(AMOUNT_OF_VARIABLES);

	if ((*m3SP).load("m3s_" + s + "_0.txt")) {

		GAOptimizer optimizer(m3SP, populationSize, probabilityOfCrossover, probabilityOfMutation);
		optimizer.initialize();

		for (int i = 0; i < amountOfIteration; i++) {
			optimizer.runIteration();
			cout << i << ") ";
			optimizer.getBestGAIndividual()->showGenotype();
		}

		cout << endl << "BestOne: ";
		optimizer.optimize(optimizer.getBestGAIndividual(), 1)->showGenotype();
	}


	return 0;


}

