#include <iostream>
#include "Queue.hpp"
#include <queue>
using std::cout, std::cin, std::endl;

int main() {
	Queue<int> q1;
	q1.push(1).push(2).push(3).push(4).push(5).push(6);
	while (!q1.empty()) {
		cout << q1.top() << ' ';
		q1.pop();
	}
	cout << endl;
	q1.push(10);
	Queue<int> q2{std::move(q1)};
	try {
		cout << q1.top() << endl;
	} catch (const std::out_of_range& err) {
		cout << err.what() << endl;
	}
	Queue<int> q3{1, 2, 3, 4};
	Queue<int> q4{q3};
	Queue<int> q5 = Queue<int> {99, 100, 101};
	q3 = Queue<int> {69, 70, 71};
	cout << q3 << ' ' << q3.size() << endl;
	cout << q4 << ' ' << q4.size() << endl;
	cout << q5 << ' ' << q5.size() << endl;
	return 0;
}