
#include "TreeDynamic.h"
#include "Table.h"
#include <iostream>
//Node and Tree
void treeDynamicTest() {
	TreeDynamic<int>* root = new TreeDynamic<int>();

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


	TreeDynamic<int>* root_1 = new TreeDynamic<int>();

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

	/*cout << "Before root: ";
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
	cout << endl;*/

	root->printTreeReal();
	int* temp = new int;

	temp = root->sum();
	cout << "Suma: " << *temp << endl;

	delete root;
	delete root_1;

}
void treeTest2() {
	TreeDynamic<int>* root = new TreeDynamic<int>();

	root->getRoot()->setValue(1);
	root->getRoot()->addNewChild();
	root->getRoot()->addNewChild();


	root->getRoot()->getChild(0)->addNewChild();
	root->getRoot()->getChild(0)->addNewChild();
	root->getRoot()->getChild(0)->addNewChild();
	root->getRoot()->getChild(1)->addNewChild();
	root->getRoot()->getChild(1)->addNewChild();

	root->getRoot()->getChild(0)->setValue(2);
	root->getRoot()->getChild(1)->setValue(3);

	root->getRoot()->getChild(0)->getChild(0)->setValue(24);
	root->getRoot()->getChild(0)->getChild(1)->setValue(28);
	root->getRoot()->getChild(0)->getChild(2)->setValue(21);

	root->getRoot()->getChild(1)->getChild(0)->setValue(32);
	root->getRoot()->getChild(1)->getChild(1)->setValue(30);

	root->getRoot()->getChild(0)->getChild(0)->addNewChild();
	root->getRoot()->getChild(0)->getChild(0)->addNewChild();

	root->getRoot()->getChild(0)->getChild(0)->getChild(0)->setValue(245);
	root->getRoot()->getChild(0)->getChild(0)->getChild(1)->setValue(256);




	root->printTreeReal();

}
void treeTest3() {
	TreeDynamic<int>* root = new TreeDynamic<int>();

	root->getRoot()->setValue(1);
	root->getRoot()->addNewChild();
	root->getRoot()->addNewChild();


	root->getRoot()->getChild(0)->setValue(2);
	root->getRoot()->getChild(1)->setValue(3);

	root->getRoot()->getChild(0)->addNewChild();
	root->getRoot()->getChild(1)->addNewChild();

	root->getRoot()->getChild(0)->getChild(0)->setValue(4);
	root->getRoot()->getChild(1)->getChild(0)->setValue(5);


	root->getRoot()->getChild(0)->getChild(0)->addNewChild();
	root->getRoot()->getChild(1)->getChild(0)->addNewChild();

	root->getRoot()->getChild(0)->getChild(0)->getChild(0)->setValue(6);
	root->getRoot()->getChild(1)->getChild(0)->getChild(0)->setValue(7);

	root->getRoot()->getChild(0)->getChild(0)->getChild(0)->addNewChild();
	root->getRoot()->getChild(0)->getChild(0)->getChild(0)->addNewChild();

	root->getRoot()->getChild(0)->getChild(0)->getChild(0)->getChild(0)->setValue(8);
	root->getRoot()->getChild(0)->getChild(0)->getChild(0)->getChild(1)->setValue(9);

	root->getRoot()->getChild(1)->getChild(0)->getChild(0)->addNewChild();
	root->getRoot()->getChild(1)->getChild(0)->getChild(0)->addNewChild();

	root->getRoot()->getChild(1)->getChild(0)->getChild(0)->getChild(0)->setValue(10);
	root->getRoot()->getChild(1)->getChild(0)->getChild(0)->getChild(1)->setValue(11);

	root->getRoot()->getChild(0)->getChild(0)->getChild(0)->getChild(0)->addNewChild();
	root->getRoot()->getChild(1)->getChild(0)->getChild(0)->getChild(0)->addNewChild();

	root->getRoot()->getChild(0)->getChild(0)->getChild(0)->getChild(0)->getChild(0)->setValue(12);
	root->getRoot()->getChild(1)->getChild(0)->getChild(0)->getChild(0)->getChild(0)->setValue(13);

	

	

	root->printTreeReal();
}
void treeDynamicTestString() {
	TreeDynamic<string>* root = new TreeDynamic<string>();

	root->getRoot()->addNewChild();
	root->getRoot()->addNewChild();

	root->getRoot()->getChild(0)->addNewChild();
	root->getRoot()->getChild(0)->addNewChild();
	root->getRoot()->getChild(1)->addNewChild();
	root->getRoot()->getChild(1)->addNewChild();

	root->getRoot()->getChild(0)->setValue("jeden");
	root->getRoot()->getChild(1)->setValue("dwa");

	root->getRoot()->getChild(0)->getChild(0)->setValue("jedenascie");
	root->getRoot()->getChild(0)->getChild(1)->setValue("dwanascie");
	root->getRoot()->getChild(1)->getChild(0)->setValue("dwadziescia jeden");
	root->getRoot()->getChild(1)->getChild(1)->setValue("dwadziescia dwa");


	TreeDynamic<string>* root_1 = new TreeDynamic<string>();

	root_1->getRoot()->addNewChild();
	root_1->getRoot()->addNewChild();

	root_1->getRoot()->getChild(0)->addNewChild();
	root_1->getRoot()->getChild(0)->addNewChild();
	root_1->getRoot()->getChild(1)->addNewChild();
	root_1->getRoot()->getChild(1)->addNewChild();

	root_1->getRoot()->getChild(0)->setValue("trzy");
	root_1->getRoot()->getChild(1)->setValue("cztery");

	root_1->getRoot()->getChild(0)->getChild(0)->setValue("trzydziesci jeden");
	root_1->getRoot()->getChild(0)->getChild(1)->setValue("trzydziesci dwa");
	root_1->getRoot()->getChild(1)->getChild(0)->setValue("czterdziesci jeden");
	root_1->getRoot()->getChild(1)->getChild(1)->setValue("czterdziesci dwa");

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
//Table
void templateTest()
{
	Table<int> tabInt;
	Table<double*> tabDoublePoint;
	tabInt.setLength(10);
	tabInt.setElement(1, 22);
	int val = *(tabInt.getElement(1));
	double myDoub = 5;
	tabDoublePoint.setLength(2);
	tabDoublePoint.setElement(1, &myDoub);
	**(tabDoublePoint.getElement(1)) = 5;

	string type;
	type = tabInt.getKnownType();
	cout << type << endl;
	type = tabDoublePoint.getKnownType();
	cout << type << endl;

}
//Main
int main()
{
	
	treeDynamicTest();
	//treeTest2();
	//treeTest3();
	cout << endl;
	//treeDynamicTestString();
	//templateTest();
}
