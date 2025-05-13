#include <iostream>
#include "MojNizInt.hpp"

using std::cout, std::cin, std::endl;

int main() {
	MojNizInt a{1, 2, 3, 4, 5};
	MojNizInt b{a};
	b = MojNizInt{99, 100, 101};
	cout << a++ << endl;
	cout << a << endl;
	a.push_back(5);
	cout << a << endl;
	cout << a * 5 << endl;
	cout << b.size() << endl;
	a = b;
	try {
		a.at(50);
	} catch (const std::invalid_argument& e) {
		cout << e.what() << endl;
	}
	try {
		cout << a + MojNizInt{1, 2, 3, 4} << endl;
	} catch (const std::invalid_argument& e) {
		cout << e.what() << endl;
	}
	try {
		cout << a + b << endl;
	} catch (const std::invalid_argument& e) {
		cout << e.what() << endl;
	}
	return 0;
}