#include <iostream>
#include <vector>
#include <list>
using std::cout, std::cin, std::endl;

template<typename cont, typename lambda>
cont filter(const cont& container, lambda predicate) {
	cont result;
	for (const auto& el : container)
		if (predicate(el))
			result.push_back(el);
	return result;
}

int main() {
	std::list<int> numbers;
	cout << "Unesite brojeve (ctrl+D za prekid):" << endl;
	for (
		int input;
		cin >> input;
		numbers.push_back(input)
	);
	auto filtered = filter(numbers, [](int n) {
		return !(n & 1);
	});
	for (const auto& number : filtered)
		cout << number << ' ';
	cout << endl;
	return 0;
}