#include <iostream>
#include "MojNiz.hpp"
using std::cout, std::cin, std::endl;

int main() {
	MojNiz<double> c;
	MojNiz<int> a{1, 2, 1, 3, 4};
	MojNiz<int> b{4, 5, 6, 8, 9};
	MojNiz<int> d{c};
	b = a;
	a = MojNiz<char> {65, 66, 67, 68, 69};
	c = a + b;
	cout << c << endl;
	cout << b << endl;
	b.push_back(25);
	cout << b << endl;
	cout << a << endl;
	a.pop_back();
	cout << a << endl;
	cout << a * 2 << endl;
	try {
		cout << a + a << endl;
	} catch (const std::domain_error& e) {
		cout << e.what() << endl;
	}
	cout << a++ << endl;
	cout << ++a << endl;
	return 0;
}