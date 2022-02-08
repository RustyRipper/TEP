#include "GAIndividual.h"

using namespace std;

class GAOptimizer {
public:
	GAOptimizer();
	GAOptimizer(int populationSize, double crossoverProbability, double mutationProbability);
	~GAOptimizer();

	bool initialize(string path);
	void runIteration();
	GAIndividual* getBestGAIndividual();
	GAIndividual* optimize(GAIndividual* newOne, int amountOptimize);
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
};
