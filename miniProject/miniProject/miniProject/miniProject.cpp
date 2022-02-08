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
	string filePath = "m" + to_string(AMOUNT_OF_VARIABLES_IN_THE_CLAUSE) + "s_" + to_string(AMOUNT_OF_VARIABLES) + "_0.txt";

	GAOptimizer optimizer(populationSize, probabilityOfCrossover, probabilityOfMutation);

	if (optimizer.initialize(filePath)) {

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

