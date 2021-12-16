#include <iostream>
#include "Tab.h"

Tab::Tab(const Tab& other) {
	copy(other);
	std::cout << "Copy ";
}
Tab::Tab(Tab&& other) noexcept {
	move(other);
	std::cout << "MOVE ";
}

Tab::~Tab() {
	if (tab != NULL) delete[] tab;
	std::cout << "Destr ";
}

bool Tab::setSize(int newSize) {
	if (newSize < 1 || newSize > 100)
		return false;

	size = newSize;
	delete[] tab;

	tab = new int[size];
	return true;
}


Tab Tab::operator=(const Tab& other) {
	if (tab != NULL) delete[] tab;

	copy(other);
	std::cout << "op= ";

	return *this;
}


Tab Tab::operator=(Tab&& other) noexcept {
	if (tab != NULL) delete[] tab;

	move(other);
	std::cout << "MOVE op= ";

	return *this;
}

void Tab::copy(const Tab& other) {
	tab = new int[other.size];
	size = other.size;

	for (int i = 0; i < other.size; i++)
		tab[i] = other.tab[i];
}

void Tab::move(Tab& other)
{
	tab = other.tab;
	size = other.size;
	other.tab = NULL;
	other.size = 0;
}
