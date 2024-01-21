#include <iostream>
#include <list>
#include <functional>
using std::cout, std::cin, std::endl;

int reduce(
	const std::list<int>& numbers,
	std::function<int(int, int)> predicate,
	int start = 0
) {
	for (const auto& number : numbers)
		start = predicate(start, number);
	return start;
}

int main() {
	cout << "Unesite brojeve (ctrl + D za prekid):" << endl;
	std::list<int> numbers;
	int input;
	while (cin >> input)
		numbers.push_back(input);
	auto reduced = reduce(numbers, [](int a, int b) {
		return a + b + 1;
	}, -12);
	cout << "Svedena lista: " << reduced << endl;
	return 0;
}