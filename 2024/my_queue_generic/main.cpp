#include <iostream>
#include "Queue.hpp"
using std::cout, std::cin, std::endl;

int main() {
	Queue<int> q1;
	q1.push(1).push(2).push(3).push(4).push(5).push(6);
	cout << "q1.size() = " << q1.size() << endl;
	while (!q1.empty()) {
		cout << q1.top() << ' ';
		q1.pop();
	}
	cout << "\nq1.size() = " << q1.size() << endl;
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
	cout << q3 << "\nq3.size() = " << q3.size() << endl;
	cout << q4 << "\nq4.size() = " << q4.size() << endl;
	cout << q5 << "\nq5.size() = " << q5.size() << endl;
	return 0;
}