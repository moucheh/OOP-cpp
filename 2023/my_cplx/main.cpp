#include <iostream>
#include "cplx.hpp"

int main() {
	cplx z1 = {1, 3};
	cplx z2 = {0, 2};
	cplx z3 = {0, 2};
	cplx z4 = {0, -1};
	print_cplx(z1);
	print_cplx(z2);
	print_cplx(z3);
	print_cplx(z4);
	return 0;
}