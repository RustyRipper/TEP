#include "GAOptimizer.h"
#include <algorithm>

using namespace std;
GAOptimizer::GAOptimizer()
{
	m3SP = new Max3SatProblem();
	populationSize = 500;
	crossoverProbability = 0.4;
	mutationProbability = 0.2;
}

GAOptimizer::GAOptimizer(int populationSize, double crossoverProbability, double mutationProbability)
{

	this->m3SP = new Max3SatProblem();
	if (populationSize > 0) {
		this->populationSize = populationSize;
	}
	else {
		this->populationSize = 500;
	}

	if (crossoverProbability > 0) {
		this->crossoverProbability = crossoverProbability;
	}
	else {
		this->crossoverProbability = 0.4;
	}

	if (mutationProbability > 0) {
		this->mutationProbability = mutationProbability;
	}
	else {
		this->mutationProbability = 0.2;
	}


}

GAOptimizer::~GAOptimizer()
{
	for (int i = 0; i < (int)population.size(); i++) {
		if (population.at(i) != NULL) {
			delete population.at(i);
		}
	}
	population.clear();
	if (m3SP != NULL) {
		delete m3SP;
	}
}

bool GAOptimizer::initialize(string path)
{
	if (m3SP != NULL) {
		if (m3SP->load(path)) {
			srand((int)time(NULL));
			for (int i = 0; i < populationSize; i++) {

				population.push_back(new GAIndividual());
				population.at(i)->initialize(*m3SP);
			}
			return true;
		}
	}
	return false;
}

void GAOptimizer::runIteration()
{
	//int amountOptimize = populationSize / 10;
	vector<GAIndividual*> newPopulation;


	double percentOfEliteSolution = 0.05;
	for (int i = 0; i < (int)(population.size() * percentOfEliteSolution); i++) {
		GAIndividual* elite = new GAIndividual(*population.at(i));
		newPopulation.push_back(elite);
	}


	while (newPopulation.size() < (int)population.size()) {
		GAIndividual* parent1 = chooseParent();
		GAIndividual* parent2 = chooseParent();

		vector<GAIndividual*> children = crossover(parent1, parent2);

		for (int i = 0; i < (int)children.size(); i++) {
			children.at(i)=mutate(children.at(i));
			children.at(i)->calculateFitness(*m3SP);
			//newPopulation.push_back(optimize(children.at(i), amountOptimize));
			newPopulation.push_back(children.at(i));
		}
	}

	for (int i = 0; i < (int)population.size(); i++) {
		if (population.at(i) != NULL) {
			delete population.at(i);
		}
	}
	population.clear();

	population = newPopulation;
	sortPopulation();
}

GAIndividual* GAOptimizer::getBestGAIndividual()
{
	if (population.size() > 0) {
		if (population.at(0) != NULL) {
			return population.at(0);
		}
	}
}

GAIndividual* GAOptimizer::chooseParent()
{
	int tournament = 2;
	double percentOfBestPopulationToChoose = 0.66;
	double winFitness = 0;
	int winIndex = 0;
	double fitness = 0;
	int tempNumber = 0;

	for (int i = 0; i < tournament; i++) {
		tempNumber = (int)(rand() % (int)populationSize * percentOfBestPopulationToChoose);
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
	GAIndividual* temp = new GAIndividual(*child);
	temp->mutation(mutationProbability);
	temp->calculateFitness(*m3SP);
	temp = optimize(temp, 1);
	temp->calculateFitness(*m3SP);

	if (child->getFitness() < temp->getFitness()) {
		delete child;
		child = temp;
	}
	else {
		delete temp;
	}
	return child;
	//child->mutation(mutationProbability);
	//return child;
}

GAIndividual* GAOptimizer::optimize(GAIndividual* newOne, int amount)
{
	GAIndividual* bestOne = newOne;
	GAIndividual temp(newOne->getGenotype(), *m3SP);

	for (int i = 0; i < (int)newOne->getGenotype().size(); i = i + amount) {

		temp.getGenotype().at(i) = !temp.getGenotype().at(i);
		if (bestOne->getFitness() > temp.calculateFitness(*m3SP)) {
			temp.getGenotype().at(i) = !temp.getGenotype().at(i);
		}
		else {
			bestOne->getGenotype().at(i) = !bestOne->getGenotype().at(i);
			bestOne->calculateFitness(*m3SP);
		}
	}
	return bestOne;
}


void GAOptimizer::sortPopulation() {
	sort(population.begin(), population.end(), [](GAIndividual* l, GAIndividual* r) { return l->getFitness() > r->getFitness(); });
}