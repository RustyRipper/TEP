#include <string>
#include <iostream>
using namespace std;
class Test {
private:
    string name;

public:
    Test(string name);
    string getName();
    void print();

};

Test::Test(string otherName) {
    name = otherName;
}

string Test::getName() {
    return name;
}

void Test::print() {
    cout << name << "\n";
}


