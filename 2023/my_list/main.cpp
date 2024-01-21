#include <iostream>
#include "List.hpp"
using std::cout, std::endl;

int main() {
	List a{1, 2, 3, 4};
	a.push_back(2);
	List b{a};
	List c;
	c = a;
	List d;
	d = List{1, 2, 3};
	b.push_front(4);
	b.push_front(4);
	b.back() = 44;
	b.front() = 125;
	b.push_front(4);
	d = b;
	d.push_back(99);
	d.push_front(99);
	c.push_back(99);
	c.push_front(99);
	cout << "a addresses" << endl;
	for (auto it = a.begin(); it != a.end(); it = it->next)
		cout << it->prev << " <- " << it << " -> " << it->next << '\n';
	a.pop_front();
	a.pop_back();
	cout << "\na.size() = " << a.size() << endl;
	print_list(a);
	cout << "\nb.size() = " << b.size() << endl;
	print_list(b);
	cout << endl;
	cout << "c.size() = " << c.size() << endl;
	print_list_reverse(c);
	cout << "\nd.size() = " << d.size() << endl;
	print_list_reverse(d);
	cout << endl;
	List la{1, 2, 3, 4, 5};
	try {
		la.insert(69, 3);
	} catch (const std::out_of_range& e) {
		cout << e.what() << endl;
		return 0;
	}
	cout << "la.size() = " << la.size() << endl;
	print_list(la);
	cout << endl;
	return 0;
}