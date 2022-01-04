#include "GAIndividual.h"
#include "Max3SatProblem.h"
#include <ctime>
GAIndividual::GAIndividual()
{
	
}
GAIndividual::GAIndividual(vector<bool> solution)
{
	this->solution = solution;
}
GAIndividual::GAIndividual(const GAIndividual& other)
{
	this->solution.clear();
	for (int i = 0; i < other.solution.size(); i++) {
		solution.push_back(other.solution.at(i));
	}
}
vector<GAIndividual> GAIndividual::crossover(GAIndividual& parent1, GAIndividual& parent2,double probabilityOfCrossover)
{
	GAIndividual child1;
	GAIndividual child2;
	srand((unsigned)time(0));
	double tempProbability = (double)(rand() % 100) / 100;
	
	if (tempProbability < probabilityOfCrossover) {

		for (int i = 0; i < parent1.solution.size(); i++) {

			double temp = (double)(rand() %100)/100;

			if (temp < probabilityOfCrossover) {
				child1.solution.push_back(parent2.solution.at(i));
				child2.solution.push_back(parent1.solution.at(i));
			}
			else {
				child1.solution.push_back(parent1.solution.at(i));
				child2.solution.push_back(parent2.solution.at(i));
			}
		}
	}
	else {
		child1 = GAIndividual(parent1);
		child2 = GAIndividual(parent2);
	}
	vector<GAIndividual> newChildren;
	newChildren.push_back(child1);
	newChildren.push_back(child2);
	return newChildren;
}

void GAIndividual::mutation(GAIndividual& child,double probabilityOfMutation)
{
	vector<bool> newSolution;
	for (int i = 0; i < child.solution.size();i++) {

		double tempProbability = ((double)rand() / (RAND_MAX)) ;

		if (tempProbability < probabilityOfMutation) {
			newSolution.push_back(!child.solution.at(i));
		}
		else {
			newSolution.push_back(child.solution.at(i));
		}
	}
	this->solution = newSolution;
}

double GAIndividual::fitness()
{
	
	
	return 0.;
}

vector<bool> GAIndividual::getSolution()
{
	return solution;
}
