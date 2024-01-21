#include <iostream>

int main() {
	int a = 5, b = 7;
	auto lam = [&a, b](int x) { //lambda izraz "hvata" a po referenci
		return a * x + b; //b po vrijednosti
	};
	a = 3; // mijenja vrijednost varijable i ona ce se koristiti u izrazu ispod
	b = 4;
	std::cout << lam(5) << std::endl; //3 * 5 + 7 = 22
	return 0;
}
