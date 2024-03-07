#pragma once
#include <iostream>
#include <cmath>

extern const double zero;
extern const double one;
extern const double neg_one;
extern const double pi;

class cplx {
private:
	double _re{};
	double _im{};
public:
	//constructors

	cplx() = default;
	cplx(double, double);
	cplx(const cplx&) = default;
	cplx(cplx&&) = default;
	cplx& operator=(const cplx&) = default;
	cplx& operator=(cplx&) = default;

	~cplx() = default;

	//getters and setters

	auto get_re() const { return _re; }
	auto get_im() const { return _im; }
	void set_re(int re) { _re = re; }
	void set_im(int im) { _im = im; }

	//operators

	cplx operator+(const cplx&) const;
	cplx operator-(const cplx&) const;
	cplx operator*(const cplx&) const;
	cplx operator/(const cplx&) const;
	cplx operator!() const;

	cplx& operator+=(const cplx& op);
	cplx& operator-=(const cplx& op);
	cplx& operator*=(const cplx& op);
	cplx& operator/=(const cplx& op);

	//helper methods

	void print_cplx() const;
	void print_exp() const;
	double mod() const;
	double phase() const;
};

//helper functions

void print_cplx(const cplx&);
void print_exp(const cplx&);

std::ostream& operator<<(std::ostream& out, const cplx& c);