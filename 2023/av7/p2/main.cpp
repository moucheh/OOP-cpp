#include <iostream>
#include "operators.hpp"
#include "helpers.hpp"

using std::cout, std::endl;

int main() {
	using namespace Complex;
	// Cplx c1, c2, c3;
	// c1.re = 5.; c1.im = -2.;
	// c2.re = 3.; c2.im = 6.;
	// c3.re = 9.; c3.im = 0.;
	Cplx c1{5., -2.}, c2{3., 6.}, c3{9., 0.};
	cout << "c1=";
	printComplex(c1);
	cout << endl;
	cout << "c2=";
	printComplex(c2);
	cout << endl;
	cout << "c3=";
	printComplex(c3);
	cout << endl;
	// Ispis:
	// c1=(5-2i)
	// c2=(3+6i)
	// c3=(9)
	auto c4 = add(c1, c2);
	printComplex(c1);
	cout << " + ";
	printComplex(c2);
	cout << " = ";
	printComplex(c4);
	cout << endl;
	// Ispis:
	// (5-2i) + (3+6i) = (8+4i)
	auto c5 = sub(c4, c3);
	printComplex(c4);
	cout << " - ";
	printComplex(c3);
	cout << " = ";
	printComplex(c5);
	cout << endl;
	// Ispis:
	// (8+4i) - (9) = (-1+4i)
	auto c6 = mul(c5, c4);
	printComplex(c5);
	cout << " * ";
	printComplex(c4);
	cout << " = ";
	printComplex(c6);
	cout << endl;
	// Ispis:
	// (-1+4i) * (8+4i) = (-24+28i)
	cout << "c3=";
	printComplex(c3);
	cout << endl;
	append(c3, c5);
	append(c3, c2);
	cout << "c3=";
	printComplex(c3);
	cout << endl;
	// Ispis:
	// c3=(9)
	// c3=(11+10i)
	return 0;
}
