#include "Cplx.hpp"
#include <iostream>

using std::cout, std::endl;

int main() {
	using namespace Complex;
	Cplx cp1(3, 60), cp2(4, 30);
	cout << "Cp1: " << cp1.toString() << endl
		 << "Cp2: " << cp2.toString() << endl
		 << "Module and angle: " << endl
		 << cp1.modulus() << endl
		 << cp1.angle().getValue() << endl
		 << "Construct from module and radian: " << endl;
	double mod = 7;
	Radian r{3.1415926535};
	Cplx cp3(mod, r);
	cout << cp3.toString() << endl
		 << "Add operator: " << endl;
	auto cp4 = cp1.add(cp2);
	cout << "Cp1: " << cp1.toString() << endl
		 << "Cp2: " << cp2.toString() << endl
		 << "Cp4: " << cp4.toString() << endl
		 << "Append operator: " << endl;
	cp4.append(cp1).append(cp3);
	cout << "Cp1: " << cp1.toString() << endl
		 << "Cp3: " << cp3.toString() << endl
		 << "Cp4: " << cp4.toString() << endl
		 << "Make negative: " << std::endl;
	auto cp3Neg = cp3.makeNegative();
	cout << "Cp3: " << cp3Neg.toString() << endl;
	// Ne moze se kompajlirati:
	// odgovor: Radian konstruktor je explicit
	// Radian rad = 10.;
	return 0;
}
