#include <iostream>
#include <list>
#include <functional>
using std::cout, std::cin, std::endl;

std::list<int> Map(
	const std::list<int>& numbers,
	std::function<int(int)> predicate
) {
	std::list<int> result;
	for (const auto& number : numbers)
		result.push_back(predicate(number));
	return result;
}

int main() {
	std::list<int> numbers;
	cout << "Unesite brojeve (ctrl + D za prekid):" << endl;
	int input;
	while (cin >> input)
		numbers.push_back(input);
	cout << "Mapirani brojevi:" << endl;
	std::list<int> mapped = Map(numbers, [](int n) {
		return 2 * n + 1;
	});
	std::list<int>::const_iterator m = mapped.begin();
	for (const auto& number : numbers) {
		cout << number << " -> " << *m << ' ';
		++m;
	}
	cout << endl;
	return 0;
}
