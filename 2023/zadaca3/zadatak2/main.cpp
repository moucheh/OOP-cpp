#include <iostream>
#include <list>
using std::cout, std::cin, std::endl;

template<typename cont, typename lambda>
cont Map(const cont& container, lambda predicate) {
	cont result;
	for (const auto& el : container)
		result.push_back(predicate(el));
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
	auto Mapped = Map(numbers, [](int n) {
		return 2 * n + 1;
	});
	for (const auto& number : Mapped)
		cout << number << ' ';
	cout << endl;
	return 0;
}