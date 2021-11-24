#pragma once

#include <vector>

#include <iostream>
using namespace std;
class NodeStatic {

public:
	NodeStatic() { val = 0; parentNode = NULL; };
	void copy(NodeStatic& other);
	~NodeStatic() { cout << "usuwam " << val << "\n"; };
	void setValue(int newVal) { val = newVal; };
	int getChildrenNumber() { return(children.size()); };
	void addNewChild();
	void addExistChild(NodeStatic& node);
	NodeStatic* getChild(int childOffset);
	void print() { cout << " [" << val << "]"; };
	void printAllBelow();
	NodeStatic* getParent() const;
	void printUp();
	int getChildPosition(const NodeStatic& node);
	void deleteFromChildren();

public:
	vector<NodeStatic> children;
	NodeStatic* parentNode;
	int val;

};