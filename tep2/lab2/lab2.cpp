// lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "CTable.h"
#include <iostream>

int main()
{

	CTable c_tab_0, c_tab_1;
	c_tab_0.bSetNewSize(6);
	c_tab_1.bSetNewSize(4);
	c_tab_0 = c_tab_1;


	CTable c_tab_2, c_tab_3;
	c_tab_2.bSetNewSize(6);
	c_tab_3.bSetNewSize(4);
	c_tab_2.vSetValueAt(0, 1);
	c_tab_2.vSetValueAt(1, 2);
	c_tab_2.vSetValueAt(2, 3);
	c_tab_2.vSetValueAt(3, 4);
	c_tab_2.vSetValueAt(4, 5);
	c_tab_2.vSetValueAt(5, 6);

	c_tab_3.bSetNewSize(4);
	c_tab_3.vSetValueAt(0, 51);
	c_tab_3.vSetValueAt(1, 52);
	c_tab_3.vSetValueAt(2, 53);
	c_tab_3.vSetValueAt(3, 54);
	//c_tab_2 = c_tab_3;
	c_tab_3.vSetValueAt(2, 123);
	c_tab_2.vPrint();
	c_tab_3.vPrint();

	std::cout << "zadanie 4 \n";
	CTable c_tab_4;
	c_tab_4 = c_tab_2 + c_tab_3;
	
	
	std::cout << "Tablica 4 po konkatenacji (2+3) \n";
	c_tab_4.vPrint();
	c_tab_2.vSetValueAt(2, 31);
	std::cout << "Tablica 2 po zmianie\n";
	c_tab_2.vPrint();
	std::cout << "Tablica 4 po zmianie\n";
	c_tab_4.vPrint();

	
	CTable c_tab_5("piatka",6);
	c_tab_5.vSetValueAt(0, 0);
	c_tab_5.vSetValueAt(1, 1);
	c_tab_5.vSetValueAt(2, 2);
	c_tab_5.vSetValueAt(3, 3);
	c_tab_5.vSetValueAt(4, 4);
	c_tab_5.vSetValueAt(5, 5);
	std::cout << "Tablica 5 przed\n";
	c_tab_5.vPrint();

	c_tab_5++;
	std::cout << "Tablica 5 po zmianie\n";
	c_tab_5.vPrint();
}
