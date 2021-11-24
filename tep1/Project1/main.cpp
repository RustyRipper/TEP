#include <iostream>
#include "function1.h"
#include "function2.h"
#include "function3.h"
#include "CTable.h"

int main() {

	std::cout << "function1: \n";
	v_alloc_table_add_5(5);

	std::cout << "\nfunction2: \n";
	int** pi_table;

	b_alloc_table_2_dim(&pi_table, 5, 3);
	std::cout << "\nwartosc [0][0]: " << **pi_table << "\n";

	std::cout << "\nfunction3: \n";
	std::cout << "true 1, false  0: " << b_dealloc_table_2_dim(pi_table, 5, 3);

	std::cout << "\nex4: \n";
	CTable cTable;
	CTable cTable2("drugi", 5);
	cTable2.bSetNewSize(3);
	CTable cTable3(cTable);
	CTable* clone;
	clone = cTable2.pcClone();
	(*clone).vSetName("drugi_klon nie kopia ");

	std::cout << "nazwa cTable2: " << cTable2.getName() << "\n";
	std::cout << "nazwa klona(cTable2): " << (*clone).getName() << "\n";
	std::cout << cTable.getArray() << "\n" << cTable3.getArray() << "\n";

	cTable.v_mod_tab(&cTable2, 6);
	std::cout << "ilosc cTable2 &: " << cTable2.getLength() << "\n";
	cTable.v_mod_tab(cTable2, 7);
	std::cout << "ilosc cTable2: " << cTable2.getLength() << "\n";

}