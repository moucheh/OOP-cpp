#include <iostream>
struct B {
	//B nema default constructor, jer je napisan
	//bilo koji drugi konstruktor
	//u tom slucaju kompajler nece praviti
	//implicitno
	//default constructor
	B(std::string s) {
		std::cout << 3 << s;
	}
	B(const char* s) {
		std::cout << 4 << s;
	}
	//trebalo je vodjika const dodati,
	//jer je A::foo() oznacen kao const
	//znaci moze pozivati samo const metode
	void foo() const {
		std::cout << 5;
	}
	~B() { std::cout << 9;}
};