// Napisati program koji trazi unos decimalnog broja,
// te brise sve 0 iza zareza unesenog broja. Ukoliko
// su iza zareza sve nule program treba da izbrise i
// decimalnu tacku.
//
// Primjeri:
// Unesite broj: 5.41000
// 5.41
//
// Unesite broj: 5
// 5
//
// Unesite broj: 5.00000
// 5
//
// Unesite broj: 5000
// 5000
//
// Unesite broj: 5000.
// 5000

#include <iostream>
#include <string>
using std::cout, std::cin, std::endl;

int main() {
	double input;
	cout << "Unesite broj: ";
	cin >> input;
	std::string s = std::to_string(input);
	auto hasDot = false;
	for (const auto& i : s) {
		if (i == '.') {
			hasDot = true;
			break;
		}
	}
	if (hasDot) {
		while (s.back() == '0') s.pop_back();
		if (s.back() == '.') s.pop_back();
	}
	cout << "Unijeli ste: " << s << endl;
	return 0;
}