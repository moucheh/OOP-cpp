#include <iostream>
#include <vector>
#include <functional>
using std::cout, std::cin, std::endl;

typedef std::vector<std::function<bool(int)>> Functions;

void default_if_not_all(
	std::vector<int>& numbers,
	Functions& criteria,
	int def = -1
) {
	for (auto& number : numbers)
		for (const auto& criterium : criteria)
			if (!(criterium(number))) number = def;
}

int main() {
	std::vector<int> numbers;
	cout << "Unesite brojeve (ctrl + D za prekid): " << endl;
	int input;
	while (cin >> input)
		numbers.push_back(input);
	Functions criteria{
		[](int n) {
			return n % 5 == 0;
		},
		[](int n) {
			return n > 0;
		},
		[](int n) {
			return n < 99;
		}
	};
	default_if_not_all(numbers, criteria);
	cout << "Ispis: " << endl;
	for (const auto& number : numbers)
		cout << number << '\t';
	cout << endl;
	return 0;
}