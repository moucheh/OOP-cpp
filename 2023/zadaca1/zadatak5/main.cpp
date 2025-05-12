#include <iostream>
#include <algorithm>
#include <vector>
using std::cout, std::cin, std::endl;

int main() {
	int num;
	cout << "Enter an integer: ";
	cin >> num;
	std::vector<int> v;
	while (num != 0) {
		v.push_back(num % 10);
		num /= 10;
	}
	long product = 1;
	long sum = 0;
	for (const auto& i : v) {
		cout << i;
		product *= i;
		sum += i;
	}
	std::sort(v.begin(), v.end());
	cout << "\n"
		 << v.front()
		 << "\n"
		 << v.back()
		 << "\n"
		 << sum
		 << "\n"
		 << product
		 << endl;
	return 0;
}