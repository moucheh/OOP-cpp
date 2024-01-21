#include <iostream>
#include <list>
#include <functional>
using std::cout, std::cin, std::endl;

typedef std::list<int> cont;
typedef cont::const_iterator cont_it;
typedef std::function<bool(int)> func;

cont partition(cont_it __begin, cont_it __end, func predicate) {
	cont result;
	for (; __begin != __end; ++__begin)
		if (predicate(*__begin))
			result.push_front(*__begin);
		else
			result.push_back(*__begin);
	return result;
}

int main() {
	cout << "Unesite brojeve (ctrl+D za prekid):" << endl;
	int input;
	std::list<int> numbers;
	while (cin >> input)
		numbers.push_back(input);
	cont sorted = ::partition(numbers.begin(), numbers.end(),
	[](int n) {
		return n > 0;
		// return !(n % 10);
		// return std::abs(n) > 99;
	});
	cout << "Sortirani brojevi:" << endl;
	for (const auto& i : sorted)
		cout << i << "\t";
	cout << endl;
	return 0;
}