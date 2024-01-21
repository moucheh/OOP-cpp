#include <iostream>
#include <list>
#include <functional>
using std::cout, std::cin, std::endl;

std::list<int> filter(
	const std::list<int>& numbers,
	std::function<bool(int)> predicate
) {
	std::list<int> result;
	for (const auto& number : numbers)
		if (predicate(number))
			result.push_back(number);
	return result;
}

int main() {
	std::list<int> numbers;
	cout << "Unesite brojeve (ctrl + D za prekid): " << endl;
	int input;
	while (cin >> input)
		numbers.push_back(input);
	auto filtered = filter(numbers, [](int n) {
		return !(n & 1);
	});
	cout << "Filtrirani brojevi:" << endl;
	for (const auto& number : filtered)
		cout << number << '\t';
	cout << endl;
	return 0;
}