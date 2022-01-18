#include "GAIndividual.h"
#include "Max3SatProblem.h"
#include <time.h>

GAIndividual::GAIndividual()
{
	fitness = 0;
}

GAIndividual::GAIndividual(vector<bool> solution, Max3SatProblem& m3SP)
{
	this->solution.clear();
	for (int i = 0; i < solution.size(); i++) {
		this->solution.push_back(solution.at(i));
	}
	fitness = calculateFitness(m3SP);
}

GAIndividual::GAIndividual(const GAIndividual& other)
{
	this->solution.clear();
	for (int i = 0; i < other.solution.size(); i++) {
		solution.push_back(other.solution.at(i));
	}
	fitness = other.fitness;
}

void GAIndividual::initialize(Max3SatProblem& m3SP)
{
	for (int i = 0; i < AMOUNT_OF_VARIABLES; i++) {
		solution.push_back(rand() % 2);
	}
	calculateFitness(m3SP);
}

vector<GAIndividual*>& GAIndividual::crossover(GAIndividual* parent1, GAIndividual* parent2, double probabilityOfCrossover)
{
	GAIndividual* child1;
	GAIndividual* child2;

	int tempProbability = rand() % 100;

	if (tempProbability < probabilityOfCrossover * 100) {
		int temp = 0;
		child1 = new GAIndividual();
		child2 = new GAIndividual();

		for (int i = 0; i < parent1->solution.size(); i++) {

			temp = rand() % 100;

			if (temp < probabilityOfCrossover * 100) {
				child1->solution.push_back(parent2->solution.at(i));
				child2->solution.push_back(parent1->solution.at(i));
			}
			else {
				child1->solution.push_back(parent1->solution.at(i));
				child2->solution.push_back(parent2->solution.at(i));
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
	double tempProbability;
	int index;
	for (int i = 0; i < solution.size() / 10; i++) {

		tempProbability = rand() % 100;
		if (tempProbability < probabilityOfMutation * 100) {
			index = rand() % solution.size();
			this->solution.at(index) = !solution.at(index);
		}
	}
}

double GAIndividual::getFitness()
{
	return fitness;
}

vector<bool> GAIndividual::getSolution()
{
	return solution;
}

void GAIndividual::showSolution()
{
	for (int i = 0; i < solution.size(); i++) {
		std::cout << solution.at(i);
	}
	cout << "  Fitness = " << fitness << endl;
}

double GAIndividual::calculateFitness(Max3SatProblem& m3SP)
{
	fitness = m3SP.compute(solution);
	return fitness;
}
