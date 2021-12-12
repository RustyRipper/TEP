#pragma once
#include "NodeDynamic.h"


template <typename T> class TreeDynamic
{
private:
	NodeDynamic<T>* root;
public:
	TreeDynamic() { root = new NodeDynamic<T>(); };
	~TreeDynamic();
	NodeDynamic<T>* getRoot() { return(root); }
	void printTree();
	bool moveSubtree(NodeDynamic<T>* newParentNode, NodeDynamic<T>* newChildNode);
	void printTreeReal();
	T* sum();
};

using namespace std;

template <typename T>
TreeDynamic<T>::~TreeDynamic()
{
	delete root;
}

template <typename T>
void TreeDynamic<T>::printTree()
{
	(*root).printAllBelow();
}

template <typename T>
bool TreeDynamic<T>::moveSubtree(NodeDynamic<T>* newParentNode, NodeDynamic<T>* newChildNode)
{
	if (newParentNode == NULL) {
		return false;
	}

	if (newChildNode != NULL) {
		newChildNode->deleteFromChildren();
	}

	newParentNode->addExistChild(newChildNode);

	return true;
}

template <typename T>
void TreeDynamic<T>::printTreeReal()
{
	root->print();

	root->printTreeReal();
}

template <typename T>
T* TreeDynamic<T>::sum() {
	
	return NULL;
}
template <>
int* TreeDynamic<int>::sum() {
	int* sum = new int;
	*sum =root->sumHelp();
	return sum;
}
template <>
double* TreeDynamic<double>::sum() {
	double* sum = new double;
	*sum = root->sumHelp();
	return sum;
}
