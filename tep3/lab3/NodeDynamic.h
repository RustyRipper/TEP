
#include <iostream>

#include <vector>

using namespace std;

class NodeDynamic
{
public:
	NodeDynamic() { val = 0; parentNode = NULL; };
	~NodeDynamic();
	void deleteAllChildren();
	void setValue(int newVal) { val = newVal; };
	int getChildrenNumber() { return children.size(); };
	void addNewChild();
	void addExistChild(NodeDynamic* node);
	NodeDynamic* getChild(int childOffset);
	void print() { cout << " [" << val << "]"; };
	void printAllBelow();
	void printUp();
	void deleteFromChildren();
private:
	vector<NodeDynamic*> children;
	NodeDynamic* parentNode;
	int val;

};

