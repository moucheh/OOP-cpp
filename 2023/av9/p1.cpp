#include <iostream>
#include <functional>

int* foo(std::function<void()>& f) {
	int* n = new int(10);
	f = [n]() {
		std::cout << *n << std::endl;
	};
	return n;
}

int main() {
	std::function<void()> f;
	int* n = foo(f);
	f();
	delete n;
	return 0;
}