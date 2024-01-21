#include <iostream>
#include <list>
using std::cout, std::cin, std::endl;

typedef std::list<int> cont;
typedef cont::const_iterator cont_it;

cont even_odd(cont_it __begin, cont_it __end) {
	cont result;
	for (; __begin != __end; ++__begin)
		if (*__begin & 1)
			result.push_back(*__begin);
		else
			result.push_front(*__begin);
	return result;
}

int main() {
	cout << "Unesite brojeve (ctrl+D za prekid):" << endl;
	int input;
	std::list<int> numbers;
	while (cin >> input)
		numbers.push_back(input);
	cont sorted = even_odd(numbers.begin(), numbers.end());
	cout << "Sortirani brojevi:" << endl;
	for (const auto& number : sorted)
		cout << number << '\t';
	cout << endl;
	return 0;
}