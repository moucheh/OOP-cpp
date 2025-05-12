#include "helpers.hpp"
#include <iostream>

namespace Complex {
	using std::cout;
	void printComplex(const Cplx& cplx) {
		if (cplx.re == 0 && cplx.im == 0) {
			cout << "(0)";
			return;
		}
		if (cplx.re != 0)
			cout << '(' << cplx.re;
		else
			cout << '(';
		if (cplx.im == 0)
			cout << ')';
		else if (cplx.im > 0)
			if (cplx.im == 1)
				cout << '+' << "i)";
			else
				cout << '+' << cplx.im << "i)";
		else {
			if (cplx.im == -1)
				cout << "-i)";
			else
				cout << cplx.im << "i)";
		}
	}
	void append(Cplx& lhs, const Cplx& rhs) {
		lhs.re += rhs.re;
		lhs.im += rhs.im;
	}
}
