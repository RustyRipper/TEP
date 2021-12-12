#include <iostream>

#include <vector>

using namespace std;

template <typename T> class NodeDynamic
{
private:
	vector<NodeDynamic*> children;
	NodeDynamic<T>* parentNode;
	T val;
public:
	NodeDynamic();
	~NodeDynamic();
	void setValue(T newVal) { val = newVal; };
	int getChildrenNumber() { return children.size(); };
	void addNewChild();
	void addExistChild(NodeDynamic<T>* node);
	NodeDynamic<T>* getChild(int childOffset);
	void print() { cout << " [" << val << "]"; };
	void printAllBelow();
	void printUp();
	void printTreeReal();
	void deleteFromChildren();
	
	T sumHelp();
};


template <typename T>
NodeDynamic<T>::NodeDynamic()
{
	val = T();
	parentNode = NULL;
}

template <>
NodeDynamic<int>::NodeDynamic()
{
	val = 0;
	parentNode = NULL;
}

template <>
NodeDynamic<string>::NodeDynamic()
{
	val = "zero";
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
void NodeDynamic<T>::printTreeReal()
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
	node->printTreeReal();


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


template<>
int NodeDynamic<int>::sumHelp() {
	int sum = val;
	for (int i = 0; i < children.size(); i++) {
		sum = sum + (children.at(i)->sumHelp());
	}
	return sum;
}

template<>
double NodeDynamic<double>::sumHelp() {
	double sum = val;
	for (int i = 0; i < children.size(); i++) {
		sum = sum + (children.at(i)->sumHelp());
	}
	return sum;
}