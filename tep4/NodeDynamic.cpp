#include "NodeDynamic.h"

template <typename T>
NodeDynamic<T>::NodeDynamic()
{
	val = 0;
	parentNode = NULL;
}

template <typename T>
NodeDynamic<T>::~NodeDynamic()
{
	cout << "usuwam " << val << "\n";
	for (int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
}

template <typename T>
void NodeDynamic<T>::addNewChild()
{
	NodeDynamic* node = new NodeDynamic;
	node->parentNode = this;
	children.push_back(node);
}

template <typename T>
void NodeDynamic<T>::addExistChild(NodeDynamic* node)
{
	node->parentNode = this;
	children.push_back(node);
}

template <typename T>
NodeDynamic<T>* NodeDynamic<T>::getChild(int childOffset)
{
	if (childOffset > getChildrenNumber()) {
		return NULL;
	}
	return children[childOffset];
}

template <typename T>
void NodeDynamic<T>::printAllBelow()
{
	print();
	for (int i = 0; i < getChildrenNumber(); i++) {

		(*children[i]).printAllBelow();
	}
}

template <typename T>
void NodeDynamic<T>::printUp()
{
	print();
	if (parentNode == NULL) {
		return;
	}

	parentNode->printUp();
}

template <typename T>
void NodeDynamic<T>::printTree()
{
	NodeDynamic* node = new NodeDynamic();
	cout << endl;
	if (children.size() == 0) {
		return;
	}
	for (int i = 0; i < children.size(); i++) {

		(*children[i]).print();
		cout << " ";
		for (int j = 0; j < children[i]->children.size(); j++) {
			node->addExistChild(children[i]->children[j]);
		}
	}
	node->printTree();

}

template <typename T>
void NodeDynamic<T>::deleteFromChildren()
{
	for (int i = 0; i < parentNode->children.size(); i++)
	{
		if (parentNode->children[i] == this) {
			parentNode->children.erase(parentNode->children.begin() + i);
			return;
		}
	}
}
