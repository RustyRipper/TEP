#pragma once
#include "GAIndividual.h"
#include "Max3SatProblem.h"
#include <iostream>

using namespace std;

class GAOptimizer {
public:
	GAOptimizer();
	GAOptimizer(Max3SatProblem* m3SP,int populationSize, double crossoverProbability, double mutationProbability);
	~GAOptimizer();

	void initialize();
	void runIteration();
	GAIndividual* getBestGAIndividual();
	void sortPopulation();
private:
	Max3SatProblem* m3SP;
	int populationSize;
	double crossoverProbability;
	double mutationProbability;

	
	vector<GAIndividual*> population;

	GAIndividual* chooseParent();
	vector<GAIndividual*> crossover(GAIndividual* parent1, GAIndividual* parent2);
	GAIndividual* mutate(GAIndividual* child);
	GAIndividual* optimize(GAIndividual* newOne, int amountOptimize);
	
};
