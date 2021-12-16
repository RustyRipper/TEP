#include <iostream>
#include "MySmartPointer.h"
#include "Tab.h"
#include "Table.h"
#include "Test.h"
using namespace std;

int main() {

	/* if (1 > 0) {
		 MySmartPointer<Test> mSP1(new Test("Test1"));
		 if (1 > 0) {
			 MySmartPointer<Test> mSP2(new Test("Test2"));
			 mSP2->print();
			 mSP2.printCount();
			 mSP2 = mSP1;

			 mSP2->print();
			 mSP2.printCount();

			 mSP1->print();
			 mSP1.printCount();
		 }
		 mSP1->print();
		 mSP1.printCount();
	 }*/

	/*Tab tab1, tab2;
	tab1.setSize(3);
	tab2.setSize(7);
	tab1 = std::move(tab2);
	cout << "\n";*/

	Table tab1, tab2,tab3;
	tab1.setValueAt(0, 23);
	tab2.setValueAt(1, 22);

	tab3 = std::move(tab1+tab2);

	tab1.print(); 
	tab2.print();
	tab3.print();
	return 0;
}