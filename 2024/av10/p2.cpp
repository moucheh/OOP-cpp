#include <iostream>
struct A {
	A() { std::cout << 1; }
	A(const A&) { std::cout << 2; }
	A(A&& a) { std::cout << 3; }
	~A() { std::cout << 9; }
};

void foo(const A& a0) {
	A a1(std::move(a0));
}

void bar(A&& a0) {
	A a1(a0);
}

int main (int argc, char* argv[]) {
	foo(A{});
	bar(A{});
	std::string str;
	str.append("A") = "H\n";
	std::cout << str;
	return 0;
}

//139139