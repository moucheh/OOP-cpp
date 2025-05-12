#include "operators.hpp"

namespace Complex {
	Cplx add(const Cplx& lhs, const Cplx& rhs) {
		Cplx result;
		result.re = lhs.re + rhs.re;
		result.im = lhs.im + rhs.im;
		return result;
	}
	Cplx sub(const Cplx& lhs, const Cplx& rhs) {
		Cplx result;
		result.re = lhs.re - rhs.re;
		result.im = lhs.im - rhs.im;
		return result;
	}
	Cplx mul(const Cplx& lhs, const Cplx& rhs) {
		Cplx result;
		result.re = lhs.re * rhs.re - lhs.im * rhs.im;
		result.im = lhs.re * rhs.im + lhs.im * rhs.re;
		return result;
	}
}

