#include "TreeDynamic.h"

#include <iostream>
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
void TreeDynamic<T>::printTree2()
{
	root->print();

	root->printTree();
}

