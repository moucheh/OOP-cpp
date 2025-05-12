#include <iostream>
#include <list>
using std::cout, std::cin, std::endl;

template<typename cont, typename lambda>
auto reduce(const cont& container, lambda predicate, double start = 0) {
	for (const auto& el : container)
		start = predicate(el, start);
	return start;
}

int main() {
	std::list<int> numbers;
	cout << "Unesite brojeve (ctrl+D za prekid):" << endl;
	for (
		int input;
		cin >> input;
		numbers.push_back(input)
	);
	auto reduced = reduce(numbers, [](int a, int b) {
		return a + b + 1;
	}, -12);
	cout << reduced << endl;
	return 0;
}