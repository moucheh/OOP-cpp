#include "Vector.hpp"
using std::cout, std::endl;

int main() {
	Vector a{11, 4, 15};
	std::sort(a.begin(), a.end());
	Vector b = {69, 420, 1337, 111, 123};
	Vector c{b};
	Vector d{Vector{100, 200, 300}};
	c.at(2) = 7331;
	c[0] = 731;
	Vector e;
	Vector f;
	f.assign(e.begin(), e.end());
	e.assign(a.begin(), end(a));
	cout << "a.size() = "
		 << a.size()
		 << "\na = ";
	print_Vector(a);
	cout << "\nb.size() = "
		 << b.size()
		 << "\nb = ";
	print_Vector(b);
	c.push_back(4);
	// c.at(10);
	cout << "\nc.size() = "
		 << c.size()
		 << "\nc = ";
	print_Vector(c);
	d.pop_back();
	cout << "\nd.size() = "
		 << d.size()
		 << "\nd = ";
	print_Vector(d);
	cout << "\ne.size() = "
		 << e.size()
		 << "\ne = ";
	print_Vector(e);
	cout << "\nf.size() = "
		 << f.size()
		 << "\nf = ";
	print_Vector(f);
	cout << endl;
	return 0;
}