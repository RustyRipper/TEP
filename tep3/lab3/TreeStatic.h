#include "NodeStatic.h"

class TreeStatic
{
public:

	bool moveSubtree(NodeStatic* newParentNode, NodeStatic* newChildNode);
	NodeStatic* getRoot() { return(&root); }
	void printTree();

private:
	NodeStatic root;
};