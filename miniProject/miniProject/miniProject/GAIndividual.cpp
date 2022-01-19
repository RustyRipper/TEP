#include "GAIndividual.h"
#include <time.h>

GAIndividual::GAIndividual()
{
	fitness = 0;
}

GAIndividual::GAIndividual(vector<bool> genotype, Max3SatProblem& m3SP)
{
	this->genotype.clear();
	for (int i = 0; i < (int)genotype.size(); i++) {
		this->genotype.push_back(genotype.at(i));
	}
	fitness = calculateFitness(m3SP);
}

GAIndividual::GAIndividual(const GAIndividual& other)
{
	this->genotype.clear();
	for (int i = 0; i < (int)other.genotype.size(); i++) {
		genotype.push_back(other.genotype.at(i));
	}
	fitness = other.fitness;
}

void GAIndividual::initialize(Max3SatProblem& m3SP)
{
	for (int i = 0; i < AMOUNT_OF_VARIABLES; i++) {
		genotype.push_back(rand() % 2);
	}
	calculateFitness(m3SP);
}

vector<GAIndividual*> GAIndividual::crossover(GAIndividual* parent1, GAIndividual* parent2, double probabilityOfCrossover)
{
	GAIndividual* child1;
	GAIndividual* child2;

	int tempProbability = rand() % 100;

	if (tempProbability < probabilityOfCrossover * 100) {
		int temp = 0;
		child1 = new GAIndividual();
		child2 = new GAIndividual();

		for (int i = 0; i < (int)parent1->genotype.size(); i++) {

			temp = rand() % 100;

			if (temp < probabilityOfCrossover * 100) {
				child1->genotype.push_back(parent2->genotype.at(i));
				child2->genotype.push_back(parent1->genotype.at(i));
			}
			else {
				child1->genotype.push_back(parent1->genotype.at(i));
				child2->genotype.push_back(parent2->genotype.at(i));
			}
		}
	}
	else {
		child1 = new GAIndividual(*parent1);
		child2 = new GAIndividual(*parent2);
	}
	vector<GAIndividual*> newChildren;
	newChildren.push_back(child1);
	newChildren.push_back(child2);
	return newChildren;
}

void GAIndividual::mutation(double probabilityOfMutation)
{
	double percentGenesForMutation = 0.1;
	double tempProbability = 0.0;
	int index = 0;

	for (int i = 0; i < (int)genotype.size() * percentGenesForMutation; i++) {

		tempProbability = rand() % 100;
		if (tempProbability < probabilityOfMutation * 100) {
			index = rand() % genotype.size();
			this->genotype.at(index) = !genotype.at(index);
		}
	}
}

double GAIndividual::getFitness()
{
	return fitness;
}

vector<bool> GAIndividual::getGenotype()
{
	return genotype;
}

void GAIndividual::showGenotype()
{
	for (int i = 0; i < (int)genotype.size(); i++) {
		std::cout << genotype.at(i);
	}
	cout << "  Fitness = " << fitness << endl;
}

double GAIndividual::calculateFitness(Max3SatProblem& m3SP)
{
	fitness = m3SP.compute(genotype);
	return fitness;
}
