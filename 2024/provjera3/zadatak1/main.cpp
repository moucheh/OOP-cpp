#include <iostream>
#include <stdexcept>
#include <list>
#include <vector>
using std::cout, std::cin, std::endl;

template<typename V, typename input_it, typename lambda>
V applyMid(input_it P, input_it K, lambda F) {
	int _size{};
	for (auto it = P; it != K; ++it)
		++_size;
	if (_size & 1)
		throw std::logic_error{
		"Only one element in the middle."
	};
	auto lhs = P;
	auto rhs = P;
	for (auto i = 0; i < _size / 2 - 1; ++i) {
		++lhs;
		++rhs;
	}
	++rhs;
	return F(*lhs, *rhs);
}

int main() {
	std::list<int> _list{1, 4, 3, 5, 5, 9};
	std::vector<double> _vector{2.1, 4.3, 6.5, 7.2};
	try {
		auto result1 = applyMid<int>(
						   _list.begin(),
						   _list.end(),
		[](int a, int b) {
			return a + b;
		});
		cout << "Lista rezultat: " << result1 << endl;
	} catch (const std::logic_error& e) {
		cout << e.what() << endl;
	}
	try {
		auto result2 = applyMid<double>(
						   _vector.begin(),
						   _vector.end(),
		[](double a, double b) {
			return a * b + 1.;
		});
		cout << "Vektor rezultat: " << result2 << endl;
	} catch (const std::logic_error& e) {
		cout << e.what() << endl;
	}
	return 0;
}