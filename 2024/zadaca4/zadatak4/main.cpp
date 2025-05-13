#include "Matrica.hpp"
#include <iostream>

int main() {
	Matrica<int> a(2, 2);
	a(0, 0) = 1;
	a(0, 1) = 34;
	a(1, 0) = 5;
	a(1, 1) = 100;
	Matrica<int> b(a);
	std::cout << "Matrica b:" << std::endl << b << std::endl;
	Matrica<int> c{2, 2, 1, 4, 2, 10};
	c *= 3;
	std::cout << "Matrica c:" << std::endl << c << std::endl;
	Matrica<int> d = Matrica{1, 3, 1, 2, 3};
	std::cout << "Matrica d:" << std::endl << d << std::endl;
	try {
		a += b - c;
		std::cout << "Matrica a:" << std::endl << a << std::endl;
	} catch (std::domain_error e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << a / 2 << std::endl;
	} catch (std::domain_error e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
