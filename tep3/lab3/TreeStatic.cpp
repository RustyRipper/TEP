#include "TreeStatic.h"

bool TreeStatic::moveSubtree(NodeStatic* newParentNode, NodeStatic* newChildNode)
{
	if (newParentNode == NULL || newChildNode == NULL) {
		return false;
	}

	NodeStatic* copy;
	copy = new NodeStatic();
	(*copy).copy(*newChildNode);

	newParentNode->addExistChild(*copy);
	newChildNode->deleteFromChildren();

	return true;
}

void TreeStatic::printTree()
{
	root.printAllBelow();
}
