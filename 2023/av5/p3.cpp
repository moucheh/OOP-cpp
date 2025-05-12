#include <iostream>

int main() {
	std::string s = "V5";
	auto& a = s; // s dobija novo ime a
	a = "Ref?"; // a dobija vrijednost "Ref?"
	a = a + ": Hello"; // na "Ref?" dodajemo ": Hello"
	std::cout << s << std::endl; // prethodne linije uticu na pocetni string s
	return 0;
}
