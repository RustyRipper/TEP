#include "GAOptimizer.h"
#include <iostream>
#include <algorithm>
using namespace std;
GAOptimizer::GAOptimizer()
{
	m3SP = NULL;
	populationSize = 200;
	crossoverProbability = 0.4;
	mutationProbability = 0.2;
}

GAOptimizer::GAOptimizer(Max3SatProblem* m3SP, int populationSize, double crossoverProbability, double mutationProbability)
{
	this->m3SP = m3SP;
	this->populationSize = populationSize;
	this->crossoverProbability = crossoverProbability;
	this->mutationProbability = mutationProbability;
}

GAOptimizer::~GAOptimizer()
{
	for (int i = 0; i < population.size(); i++) {
		delete population.at(i);
	}
	population.clear();
	delete m3SP;
}

void GAOptimizer::initialize()
{
	srand((int)time(NULL));
	for (int i = 0; i < populationSize; i++) {

		population.push_back(new GAIndividual());
		population.at(i)->initialize(*m3SP);
	}
}

void GAOptimizer::runIteration()
{
	int amountOptimize = populationSize / 10;
	vector<GAIndividual*> newPopulation;

	// 5% elite solutions
	for (int i = 0; i < (int)(population.size() / 20); i++) {
		GAIndividual* elite = new GAIndividual(*population.at(i));
		newPopulation.push_back(elite);
	}

	while (newPopulation.size() < population.size()) {
		GAIndividual* parent1 = chooseParent();
		GAIndividual* parent2 = chooseParent();

		vector<GAIndividual*> children = crossover(parent1, parent2);

		for (int i = 0; i < children.size(); i++) {
			mutate(children.at(i));
			children.at(i)->calculateFitness(*m3SP);
			//newPopulation.push_back(optimize(children.at(i), amountOptimize));
			newPopulation.push_back(children.at(i));
		}
		
	} 

	for (int i = 0; i < population.size(); i++) {
		delete population.at(i);
	}
	population.clear();

	population = newPopulation;
	sortPopulation();
}

GAIndividual* GAOptimizer::getBestGAIndividual()
{
	return population.at(0);
}

GAIndividual* GAOptimizer::chooseParent()
{
	double winFitness = 0;
	int winIndex = 0;
	int tournament = 2;
	double fitness = 0;
	int tempNumber = 0;

	for (int i = 0; i < tournament; i++) {
		tempNumber = (int)(rand() % (int)populationSize / 1.5);
		fitness = population.at(tempNumber)->getFitness();

		if (fitness > winFitness) {
			winFitness = fitness;
			winIndex = tempNumber;
		}
	}
	return population.at(winIndex);
}

vector<GAIndividual*> GAOptimizer::crossover(GAIndividual* parent1, GAIndividual* parent2)
{
	return GAIndividual().crossover(parent1, parent2, crossoverProbability);
}

GAIndividual* GAOptimizer::mutate(GAIndividual* child)
{
	child->mutation(mutationProbability);
	return child;
}

GAIndividual* GAOptimizer::optimize(GAIndividual* newOne, int amount)
{
	GAIndividual* bestOne = newOne;
	GAIndividual temp(newOne->getSolution(), *m3SP);

	for (int i = 0; i < newOne->getSolution().size(); i = i + amount) {

		temp.getSolution().at(i) = !temp.getSolution().at(i);
		if (bestOne->getFitness() > temp.calculateFitness(*m3SP)) {
			temp.getSolution().at(i) = !temp.getSolution().at(i);
		}
		else {
			bestOne->getSolution().at(i) = !bestOne->getSolution().at(i);
			bestOne->calculateFitness(*m3SP);
		}
	}
	return bestOne;
}


void GAOptimizer::sortPopulation() {
	sort(population.begin(), population.end(), [](GAIndividual* l, GAIndividual* r) { return l->getFitness() > r->getFitness(); });
}