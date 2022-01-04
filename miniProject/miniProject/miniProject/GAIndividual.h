#pragma once
#include <vector>
using namespace std;
class GAIndividual
{
public:
	GAIndividual();
	GAIndividual(vector<bool> solution);
	GAIndividual(const GAIndividual& other);
	vector<GAIndividual> crossover(GAIndividual& parent1, GAIndividual& parent2, double probabilityOfCrossover);
	void mutation(GAIndividual& child, double probabilityOfMutation);
	double fitness();

	vector<bool> getSolution();

private:
	vector<bool> solution;

};

