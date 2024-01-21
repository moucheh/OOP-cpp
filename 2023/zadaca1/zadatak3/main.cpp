#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using std::cout, std::cin, std::endl;

int main() {
	using triplet = std::vector<int>;
	std::vector<triplet> triplets;
	int hypotenuse;
	cout << "Enter the length of hypotenuse: ";
	cin >> hypotenuse;
	for (auto i = 3; i < hypotenuse; i++) {
		for (auto j = 3; j < hypotenuse; j++) {
			for (auto k = 3; k < hypotenuse; k++) {
				if (i > j && i > k && i < j + k && i * i == j * j + k * k) {
					triplets.push_back({k, j, i});
				}
			}
		}
	}
	for (auto& i : triplets)
		std::sort(i.begin(), i.end());
	std::set<triplet> sorted(triplets.begin(), triplets.end());
	for (const auto& i : sorted) {
		cout << '(';
		auto counter = 0;
		for (const auto& j : i) {
			if (counter == 2) {
				cout << j;
				continue;
			} else
				cout << j << ',';
			counter++;
		}
		cout << ")" << endl;
	}
	return 0;
}