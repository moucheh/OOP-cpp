#include <iostream>
#include "Handler.hpp"
//zadatak je bilo i dodati include direktive

//ispis
//NUM: 3
//Result: 15; 16; 17;

int main() {
	int num = 0;
	auto add_foo = [&num](int a, int b) {
		// ovde je trebalo dodati ref
		++num;
		return std::to_string(a + b + num);
	};
	auto sub_foo = [&num](int a, int b) {
		// ovde je trebalo dodati ref
		++num;
		return std::to_string(a - b - num);
	};
	std::vector<Handler> hs;
	Handler h1, h2, h3, h4, h5, h6;
	h1.id = h3.id = h5.id = "Add";
	h2.id = h4.id = h6.id = "Sub";
	h1.foo = h3.foo = h5.foo = add_foo;
	h2.foo = h4.foo = h6.foo = sub_foo;
	hs.push_back(h1);
	hs.push_back(h2);
	hs.push_back(h3);
	hs.push_back(h4);
	hs.push_back(h5);
	hs.push_back(h6);
	std::string addResults = provjera2(hs, "Add", 5, 9);
	std::cout << "NUM: " << num << std::endl;
	std::cout << "Result: " << addResults << std::endl;
	return 0;
}
