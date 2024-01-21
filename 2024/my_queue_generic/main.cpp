#include <iostream>
#include "Queue.hpp"
#include <queue>
using std::cout, std::cin, std::endl;

int main() {
	Queue<int> red1;
	red1.push(1).push(2).push(3).push(4).push(5).push(6);
	while (!red1.empty()) {
		cout << red1.top() << ' ';
		red1.pop();
	}
	cout << endl;
	red1.push(10);
	Queue<int> red2{std::move(red1)};
	try {
		cout << red1.top() << endl;
	} catch (const std::out_of_range& err) {
		cout << err.what() << endl;
	}
	return 0;
}