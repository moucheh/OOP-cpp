#include <iostream>
#include <functional>

int main() {
	int x = 7;
	std::function<void()> foo;
	{
		int z = 19;
		int* y = new int(12);
		foo = [&, ptr_y = y, ptr_z = &z]() {
			std::cout << x << " " << *ptr_z << " " << *ptr_y << std::endl;
		};
	}
	foo();
	return 0;
}
