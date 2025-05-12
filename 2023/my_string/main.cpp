#include <iostream>
#include "String.hpp"

using std::cout, std::cin, std::endl;

int main() {
	String fname;
	cout << "Unesite ime: ";
	cin >> fname;
	cout << "Unesite prezime: ";
	String lname;
	cin >> lname;
	String name;
	name += fname + ' ' + lname;
	cout << "Unijeli ste: " << name << endl;
	return 0;
}