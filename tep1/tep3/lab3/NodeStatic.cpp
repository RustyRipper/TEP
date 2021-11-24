#include "NodeStatic.h"


void NodeStatic::copy(NodeStatic& other) 
{
	val = other.val;
	if (&other.children != NULL) {
		for (int i = 0; i < other.children.size(); i++) {

			addNewChild();
			children[i].val = other.children[i].val;

			if (&other.children[i].children == NULL) {

			}
			else {
				children[i].copy(other.children[i]);
			}
		}
	}
}

void NodeStatic::addNewChild() 
{

	NodeStatic node;
	node.parentNode = this;
	children.push_back(node);
}

void NodeStatic::addExistChild(NodeStatic& node) 
{
	node.parentNode = this;
	children.push_back(node);
}


NodeStatic* NodeStatic::getChild(int childOffset) 
{
	if (childOffset >= getChildrenNumber()) {
		return NULL;
	}
	return &children[childOffset];
}


void NodeStatic::printAllBelow() 
{
	print();
	for (int i = 0; i < getChildrenNumber(); i++) {

		children[i].printAllBelow();
	}
}

NodeStatic* NodeStatic::getParent() const
{
	return parentNode;
}


void NodeStatic::printUp() 
{

	print();
	if (parentNode == NULL) {
		return;
	}
	parentNode->printUp();
}

void NodeStatic::deleteFromChildren() 
{
	for (int i = 0; i < parentNode->children.size(); i++)
	{
		if (&parentNode->children[i] == this) {
			parentNode->children.erase(parentNode->children.begin() + i);
			return;
		}
	}
}

int NodeStatic::getChildPosition(const NodeStatic& node) 
{
	for (int i = 0; i < children.size(); i++) {
		if (&children.at(i) == &node)
			return i;
	}
	return -1;
}