#include "NodeDynamic.h"

NodeDynamic::~NodeDynamic() 
{
	cout << "usuwam " << val << "\n";
	for (int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
}


void NodeDynamic::addNewChild()
{
	NodeDynamic* node = new NodeDynamic;
	node->parentNode = this;
	children.push_back(node);
}

void NodeDynamic::addExistChild(NodeDynamic* node)
{
	node->parentNode = this;
	children.push_back(node);
}

NodeDynamic* NodeDynamic::getChild(int childOffset)
{
	if (childOffset > getChildrenNumber()) {
		return NULL;
	}
	return children[childOffset];
}

void NodeDynamic::printAllBelow()
{
	print();
	for (int i = 0; i < getChildrenNumber(); i++) {

		(*children[i]).printAllBelow();
	}
}
void NodeDynamic::printUp()
{
	print();
	if (parentNode == NULL) {
		return;
	}

	parentNode->printUp();
}


void NodeDynamic::deleteFromChildren()
{
	for (int i = 0; i < parentNode->children.size(); i++)
	{
		if (parentNode->children[i] == this) {
			parentNode->children.erase(parentNode->children.begin() + i);
			return;
		}
	}
}
