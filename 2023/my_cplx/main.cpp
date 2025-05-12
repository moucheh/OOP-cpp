#include <iostream>
#include "cplx.hpp"
using std::cout, std::cin, std::endl;

int main() {
	cplx z1{1, 3};
	cplx z2{0, 2};
	cplx z3{0, 2};
	cplx z4{0, -1};
	cout << z1 << endl;
	cout << z2 << endl;
	cout << z3 << endl;
	cout << z4 << endl;
	return 0;
}