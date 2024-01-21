// Zakljuciti koji je ispis datog programa

#include <iostream>

int main() {
	int x = 7;
	int y = -1;
	auto lam = [&x, y](int s) mutable { //mutable -> varijabla y se moze mijenjati
		x = x + 5 - s; // 7+5-1 = 11 = x, utice na vrijednost x van lamba izraza
		y = s + 3; // 1+3 = 4,  y van lambda izraza = -1
		return s + x + y; //1+11+4 = 16
	};
	std::cout << lam(1) << " " << x << " " << y << std::endl;
	//ispis
	//16 11 -1
	return 0;
}
