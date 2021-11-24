#include "TreeStatic.h"
#include "TreeDynamic.h"

#include <iostream>


void treeTest()
{
	NodeStatic root;

	root.addNewChild();
	root.addNewChild();

	root.getChild(0)->setValue(1);
	root.getChild(1)->setValue(2);

	root.getChild(0)->addNewChild();
	root.getChild(0)->addNewChild();

	root.getChild(0)->getChild(0)->setValue(11);
	root.getChild(0)->getChild(1)->setValue(12);

	root.getChild(1)->addNewChild();
	root.getChild(1)->addNewChild();

	root.getChild(1)->getChild(0)->setValue(21);
	root.getChild(1)->getChild(1)->setValue(22);

	root.printAllBelow();
	cout << endl;
	root.getChild(0)->getChild(1)->printUp();
}
void treeStaticTest() {

	TreeStatic root;
	root.getRoot()->addNewChild();
	root.getRoot()->addNewChild();

	root.getRoot()->getChild(0)->setValue(1);
	root.getRoot()->getChild(1)->setValue(2);

	root.getRoot()->getChild(0)->addNewChild();
	root.getRoot()->getChild(0)->addNewChild();
	root.getRoot()->getChild(0)->getChild(0)->setValue(11);
	root.getRoot()->getChild(0)->getChild(1)->setValue(12);

	root.getRoot()->getChild(1)->addNewChild();
	root.getRoot()->getChild(1)->addNewChild();
	root.getRoot()->getChild(1)->getChild(0)->setValue(21);
	root.getRoot()->getChild(1)->getChild(1)->setValue(22);

	TreeStatic root_1;
	root_1.getRoot()->addNewChild();
	root_1.getRoot()->addNewChild();
	root_1.getRoot()->getChild(0)->setValue(3);
	root_1.getRoot()->getChild(1)->setValue(4);

	root_1.getRoot()->getChild(0)->addNewChild();
	root_1.getRoot()->getChild(0)->addNewChild();
	root_1.getRoot()->getChild(0)->getChild(0)->setValue(31);
	root_1.getRoot()->getChild(0)->getChild(1)->setValue(32);

	root_1.getRoot()->getChild(1)->addNewChild();
	root_1.getRoot()->getChild(1)->addNewChild();
	root_1.getRoot()->getChild(1)->getChild(0)->setValue(41);
	root_1.getRoot()->getChild(1)->getChild(1)->setValue(42);

	cout << "Before root: ";
	root.getRoot()->printAllBelow();
	cout << endl;
	cout << "Before root_1: ";
	root_1.getRoot()->printAllBelow();
	cout << endl;
	root.moveSubtree(root.getRoot()->getChild(1)->getChild(1), root_1.getRoot()->getChild(0)
	);
	cout << "After root: ";
	root.printTree();
	cout << endl;
	cout << "After root_1: ";
	root_1.printTree();
	cout << endl;

	cout << "PrintUp 32: ";
	root.getRoot()->getChild(1)->getChild(1)->getChild(0)->getChild(1)->printUp();
	cout << endl;
	cout << "PrintUp 42: ";
	root_1.getRoot()->getChild(0)->getChild(1)->printUp();
	cout << endl;
}
void treeDynamicTest() {
	TreeDynamic* root = new TreeDynamic;

	root->getRoot()->addNewChild();
	root->getRoot()->addNewChild();

	root->getRoot()->getChild(0)->addNewChild();
	root->getRoot()->getChild(0)->addNewChild();
	root->getRoot()->getChild(1)->addNewChild();
	root->getRoot()->getChild(1)->addNewChild();

	root->getRoot()->getChild(0)->setValue(1);
	root->getRoot()->getChild(1)->setValue(2);

	root->getRoot()->getChild(0)->getChild(0)->setValue(11);
	root->getRoot()->getChild(0)->getChild(1)->setValue(12);
	root->getRoot()->getChild(1)->getChild(0)->setValue(21);
	root->getRoot()->getChild(1)->getChild(1)->setValue(22);


	TreeDynamic* root_1 = new TreeDynamic;

	root_1->getRoot()->addNewChild();
	root_1->getRoot()->addNewChild();

	root_1->getRoot()->getChild(0)->addNewChild();
	root_1->getRoot()->getChild(0)->addNewChild();
	root_1->getRoot()->getChild(1)->addNewChild();
	root_1->getRoot()->getChild(1)->addNewChild();

	root_1->getRoot()->getChild(0)->setValue(3);
	root_1->getRoot()->getChild(1)->setValue(4);

	root_1->getRoot()->getChild(0)->getChild(0)->setValue(31);
	root_1->getRoot()->getChild(0)->getChild(1)->setValue(32);
	root_1->getRoot()->getChild(1)->getChild(0)->setValue(41);
	root_1->getRoot()->getChild(1)->getChild(1)->setValue(42);

	cout << "Before root: ";
	root->getRoot()->printAllBelow();
	cout << endl;
	cout << "Before root_1: ";
	root_1->getRoot()->printAllBelow();
	cout << endl;
	root->moveSubtree(root->getRoot()->getChild(1)->getChild(1), root_1->getRoot()->getChild(0)
	);
	cout << "After root: ";
	root->printTree();
	cout << endl;
	cout << "After root_1: ";
	root_1->printTree();
	cout << endl;

	cout << "PrintUp 32: ";
	root->getRoot()->getChild(1)->getChild(1)->getChild(0)->getChild(1)->printUp();
	cout << endl;
	cout << "PrintUp 42: ";
	root_1->getRoot()->getChild(0)->getChild(1)->printUp();
	cout << endl;
	delete root;
	delete root_1;

}

int main()
{
	//treeTest();
	//treeStaticTest();
	treeDynamicTest();

}
