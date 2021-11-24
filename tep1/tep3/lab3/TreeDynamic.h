#pragma once
#include "NodeDynamic.h"


class TreeDynamic
{
public:
	TreeDynamic() { root = new NodeDynamic; };
	~TreeDynamic();
	NodeDynamic* getRoot() { return(root); }
	void printTree();
	bool moveSubtree(NodeDynamic* newParentNode, NodeDynamic* newChildNode);
private:
	NodeDynamic* root;
};

