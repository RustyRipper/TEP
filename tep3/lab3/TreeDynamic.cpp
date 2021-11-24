#include "TreeDynamic.h"

#include <iostream>
using namespace std;

TreeDynamic::~TreeDynamic()
{
	delete root;
}

void TreeDynamic::printTree()
{
	(*root).printAllBelow();
}

bool TreeDynamic::moveSubtree(NodeDynamic* newParentNode, NodeDynamic* newChildNode)
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
