#include <iostream>
#include <vector>
#include <stdexcept>
using std::cout, std::cin, std::endl;

std::vector<int> fib(int n) {
	if (!std::cin)
		throw std::runtime_error{
		"Morate unijeti validan broj."
	};
	if (n <= 0)
		throw std::runtime_error{
		"Mora biti > 0."
	};
	if (n == 1) return std::vector{1};
	std::vector<int> result(n);
	result[0] = 1;
	result[1] = 1;
	for (auto i = 2; i < n; i++)
		result[i] = result[i - 1] + result[i - 2];
	return result;
}


template<typename iter, typename lambda>
iter pronadji(iter p, iter k, lambda f) {
	for (; p != k; ++p)
		if (f(*p))
			return p;
	return k;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> sekvenca;
	try {
		sekvenca = fib(n);
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
		return 0;
	}
	auto pronadjen = pronadji(
						 sekvenca.cbegin(),
						 sekvenca.cend(),
	[](int n) {
		return n % 11 == 0;
	});
	if (pronadjen == sekvenca.cend())
		std::cout << "Nije pronadjen niti jedan broj djeljiva sa 11!" << std::endl;
	else
		std::cout << *pronadjen << std::endl;
	return 0;
}