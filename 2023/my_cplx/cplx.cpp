#include "cplx.hpp"

const double zero = 0.;
const double one = 1.;
const double neg_one = -1.;
const double pi = 3.141592;

cplx::cplx(double re, double im) : _re{re}, _im{im} {}

//helper methods

void cplx::print_cplx() const {
	if (_re == zero && _im == zero) {
		std::cout << "(0)";
		return;
	}
	if (_re == zero)
		std::cout << '(';
	else
		std::cout << '(' << _re;
	if (_im > zero && _re != zero)
		std::cout << '+';
	if (_im == zero)
		std::cout << ')';
	else if (_im == one)
		std::cout << "i)";
	else if (_im == neg_one)
		std::cout << "-i)";
	else {
		std::cout << _im << "i)";
	}
}

void cplx::print_exp() const {
	if (mod() != one)
		std::cout << '{' << mod();
	else
		std::cout << '{';
	if (phase() != zero)
		std::cout << "e^(i" << phase() << "deg)";
	std::cout << '}';
}

double cplx::mod() const {
	return sqrt(_re * _re + _im * _im);
}

double cplx::phase() const {
	return atan2(_im, _re) * 180 / pi;
}

// Operators

cplx cplx::operator+(const cplx& op) const {
	return cplx{
		_re + op._re,
		_im + op._im
	};
}
cplx& cplx::operator+=(const cplx& op) {
	_re += op._re;
	_im += op._im;
	return *this;
}
cplx cplx::operator-(const cplx& op) const {
	return cplx{
		_re - op._re,
		_im - op._im
	};
}
cplx& cplx::operator-=(const cplx& op) {
	_re -= op._re;
	_im -= op._im;
	return *this;
}
cplx cplx::operator*(const cplx& op) const {
	return cplx{
		_re* op._re - _im * op._im,
		_re* op._im + _im* op._re
	};
}
cplx& cplx::operator*=(const cplx& op) {
	_re = _re * op._re - _im * op._im;
	_im = _re * op._im + _im * op._re;
	return *this;
}
cplx cplx::operator/(const cplx& op) const {
	return cplx{
		(_re * op._re + _im * op._im) /
		(op._re * op._re + op._im * op._im),
		(_im * op._re - _re * op._im) /
		(op._re * op._re + op._im * op._im)
	};
}
cplx& cplx::operator/=(const cplx& op) {
	_re = _re * op._re + _im * op._im /
		  op._re * op._re + op._im * op._im;
	_im = _im * op._re - _re * op._im /
		  op._re * op._re + op._im * op._im;
	return *this;
}
cplx cplx::operator!() const {
	return cplx{_re, -_im};
}

//helpers

void print_cplx(const cplx& Z) {
	if (Z.get_re() == zero && Z.get_im() == zero) {
		std::cout << "(0)";
		return;
	}
	if (Z.get_re() == zero)
		std::cout << '(';
	else
		std::cout << '(' << Z.get_re();
	if (Z.get_im() > zero && Z.get_re() != zero)
		std::cout << '+';
	if (Z.get_im() == zero)
		std::cout << ')';
	else if (Z.get_im() == one)
		std::cout << "i)";
	else if (Z.get_im() == neg_one)
		std::cout << "-i)";
	else {
		std::cout << Z.get_im() << "i)";
	}
}

void print_exp(const cplx& Z) {
	if (Z.mod() != one)
		std::cout << '{' << Z.mod();
	else
		std::cout << '{';
	if (Z.phase() != zero)
		std::cout << "e^(i" << Z.phase() << "deg)";
	std::cout << '}';
}

std::ostream& operator<<(std::ostream& out, const cplx& c) {
	print_cplx(c);
	return out;
}