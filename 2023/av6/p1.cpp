#include <iostream>

int main () {
	int a = 5, b = 7;
	auto lam = [&a, b](int x) { //uzima a po referenci,b po vrijednosti b = 7
		return a * x + b;
	};
	a = 3;
	b = 4;
	std::cout << lam(5) << std::endl; //3*5+7 = 22
	return 0;
}
