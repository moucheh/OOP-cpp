#include <iostream>

int a = 10;

namespace ns1 {
	int a = 20;
	namespace ns2 {
		int a = 30;
	}
}

int main() {
	using std::cout, std::endl;
	int a = 40;
	cout << "Globalno a: " << ::a << "\n"
		 << "a iz ns1: " << ns1::a << "\n"
		 << "a iz ns2 koji se nalazi u ns1: " << ns1::ns2::a << "\n"
		 << "Lokalno a: " << a << endl;
	return 0;
}
