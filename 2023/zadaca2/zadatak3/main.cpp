#include <iostream>
#include <list>
#include <functional>
#include <stdexcept>
using std::cout, std::cin, std::endl;

typedef std::list<int> cont;
typedef cont::const_iterator cont_it;
typedef std::function<bool(int)> func;

cont partition(cont_it __begin, cont_it __end, func predicate) {
	cont result;
	cont temp;
	for (cont_it temp_it = __begin; temp_it != __end; ++temp_it)
		temp.push_back(*temp_it);
	try {
		for (; __begin != __end; ++__begin)
			if (predicate(*__begin))
				result.push_front(*__begin);
			else
				result.push_back(*__begin);
		return result;
	} catch (int e) {
		cout << "Unijeli ste broj veci od 400,"
			 << " funckija u ovom slucaju vraca originalnu listu!"
			 << endl;
		return temp;
	}
}

int main() {
	cout << "Unesite brojeve:(ctrl+D za prekid):" << endl;
	int input;
	std::list<int> numbers;
	while (cin >> input)
		numbers.push_back(input);
	cont sorted = ::partition(numbers.begin(), numbers.end(), [](int n) {
		if (n > 400) throw 5;
		return n > 0;
	});
	cout << "Sortirani brojevi:" << endl;
	for (const auto& i : sorted)
		cout << i << "\t";
	cout << endl;
	return 0;
}