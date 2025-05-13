#include <iostream>
#include "MojNizInt.hpp"
using std::cout, std::cin, std::endl;

int main() {
	MojNizInt a;
	cout << "a.capacity() = " << a.capacity() << endl;
	cout << "a.size() = " << a.size() << endl;
	a.push_back(1);
	cout << std::string(20, '=') << endl;
	cout << "a = " << a << endl;
	cout << "a.capacity() = " << a.capacity() << endl;
	cout << "a.size() = " << a.size() << endl;
	a.push_back(2);
	cout << std::string(20, '=') << endl;
	cout << "a = " << a << endl;
	cout << "a.capacity() = " << a.capacity() << endl;
	cout << "a.size() = " << a.size() << endl;
	a.push_back(3);
	cout << std::string(20, '=') << endl;
	cout << "a = " << a << endl;
	cout << "a.capacity() = " << a.capacity() << endl;
	cout << "a.size() = " << a.size() << endl;
	a.push_back(4);
	cout << std::string(20, '=') << endl;
	cout << "a = " << a << endl;
	cout << "a.capacity() = " << a.capacity() << endl;
	cout << "a.size() = " << a.size() << endl;
	a.push_back(5);
	cout << std::string(20, '=') << endl;
	cout << "a = " << a << endl;
	cout << "a.capacity() = " << a.capacity() << endl;
	cout << "a.size() = " << a.size() << endl;
	a.push_back(6);
	cout << std::string(20, '=') << endl;
	cout << "a = " << a << endl;
	cout << "a.capacity() = " << a.capacity() << endl;
	cout << "a.size() = " << a.size() << endl;
	a.push_back(7);
	cout << std::string(20, '=') << endl;
	cout << "a = " << a << endl;
	cout << "a.capacity() = " << a.capacity() << endl;
	cout << "a.size() = " << a.size() << endl;
	a.push_back(8);
	cout << std::string(20, '=') << endl;
	cout << "a = " << a << endl;
	cout << "a.capacity() = " << a.capacity() << endl;
	cout << "a.size() = " << a.size() << endl;
	a.push_back(9);
	cout << std::string(20, '=') << endl;
	cout << "a = " << a << endl;
	cout << "a.capacity() = " << a.capacity() << endl;
	cout << "a.size() = " << a.size() << endl;
	cout << std::string(20, '=') << endl;
	cout << "a.front() = " << a.front() << endl;
	a.pop_back();
	cout << "a.back() = " << a.back() << endl;
	return 0;
}