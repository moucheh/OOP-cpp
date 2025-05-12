#include "Cplx.hpp"
#include <iostream>

namespace Complex {
	std::string Cplx::toString() const {
		return std::to_string(re_)
			   + "+"
			   + std::to_string(im_)
			   + std::string("i");
	}

	Cplx::Cplx(double mod_, Radian phi_)
		: re_{mod_ * phi_.cosinus()},
		  im_{mod_ * phi_.sinus()} {}

	Cplx::Cplx(double mod_, Degree phi_)
		: re_{mod_ * phi_.cosinus()},
		  im_{mod_ * phi_.sinus()} {}

	double Cplx::modulus() const {
		return sqrt(re_ * re_ + im_ * im_);
	}

	Radian Cplx::angle() const {
		return Radian{atan2(im_, re_)};
	}

	Cplx Cplx::add(const Cplx& other) const {
		Cplx temp;
		temp.re_ = re_ + other.re_;
		temp.im_ = im_ + other.im_;
		return temp;
	}

	Cplx& Cplx::append(const Cplx& other) {
		re_ += other.re_;
		im_ += other.im_;
		return *this;
	}

	Cplx Cplx::makeNegative() const {
		Cplx temp;
		temp.re_ = re_;
		temp.im_ = -im_;
		return temp;
	}
}