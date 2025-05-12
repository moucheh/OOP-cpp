#include <iostream>

using std::cout;

struct A {
	A() {
		cout << "Default constructor of A\n";
	}

	A(int x) {
		cout << "Parameterized constructor"
			 << " of A with value "
			 << x << "\n";
	}

	~A() {
		cout << "Destructor of A\n";
	}
};

struct B {
	B() {
		cout << "Default constructor of B\n";
	}

	B(int y) {
		cout << "Parameterized constructor"
			 << " of B with value "
			 << y << "\n";
	}

	~B() {
		cout << "Destructor of B\n";
	}
};

struct C {
	A a;
	B b;

	C() : b(2) {
		cout << "Constructor of C\n";
	}

	~C() {
		cout << "Destructor of C\n";
	}
};

int main() {
	C c;
	return 0;
}
