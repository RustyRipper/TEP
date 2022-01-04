#include <fstream> 
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Max3SatProblem.h"
#include "GAIndividual.h"

using namespace std;


int main()
{
	vector<bool> solutions;
	for (int i = 0; i < 50; i++) {
		solutions.push_back(false)  ;
	}
	GAIndividual in(solutions);
	Max3SatProblem m3SP;
	m3SP.load("m3s_50_0.txt");
	cout << m3SP.compute(in.getSolution()) << endl;
	GAIndividual in2(solutions);
	in2.mutation(in2, 0.35);
	cout << m3SP.compute(in2.getSolution()) << endl;
	GAIndividual in3(in2);
	vector<GAIndividual> children;
	children = in3.crossover(in, in2, 0.99);
	cout << m3SP.compute(children.at(0).getSolution()) << endl;
	cout << m3SP.compute(children.at(1).getSolution()) << endl;
	return 0;
	
	
}

