#include <iostream>

int main () {
	using std::cout, std::endl;
	auto a = 4 + 4 * 4 << 4;
	cout << a << endl;
	auto b = 4 + 4 * (4 << 4);
	cout << b << endl;
	auto c = a + 4.5 * 2 + (0xA & 0xB);
	cout << c << endl
		 << sizeof(c) << endl;
	return 0;
}