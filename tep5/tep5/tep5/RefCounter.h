#pragma once
#include "vector"
template <typename T>
class RefCounter
{
public:
	RefCounter() { count = 0; }
	~RefCounter() {
		pointers.clear();
	}
	template <typename T>
	int add(T* pointer) { 
		pointers.push_back(pointer);
		return ++count;
	}
	int dec() {
		pointers.erase(pointers.begin()+pointers.size()-1);
		return --count;
	};
	int getCount() { return count;}

	template <typename T>
	T* getPointer(int offset) {
		if (offset > pointers.size())
			return NULL;

		return pointers[offset];
	}
	int getAmountPointers() {
		return pointers.size();
	}

private:
	int count;
	std::vector<T*> pointers;
};