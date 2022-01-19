#include <vector>
#include "Max3SatProblem.h"
#include <iostream>
using namespace std;
class GAIndividual
{
public:
	GAIndividual();
	GAIndividual(vector<bool> genotype, Max3SatProblem& m3SP);
	GAIndividual(const GAIndividual& other);

	void initialize(Max3SatProblem& m3SP);
	vector<GAIndividual*> crossover(GAIndividual* parent1, GAIndividual* parent2, double probabilityOfCrossover);
	void mutation(double probabilityOfMutation);

	double calculateFitness(Max3SatProblem& m3SP);

	double getFitness();
	vector<bool> getGenotype();
	void showGenotype();

private:
	vector<bool> genotype;
	double fitness;

};

