#pragma once

#include <cmath>
#include "Consts.hpp"

namespace Complex {
	class Degree {
	private:
		double value_;
	public:
		Degree(double value)
			: value_{value} {}

		double getValue() const {
			return value_;
		}

		void setValue(double value) {
			value_ = value;
		}

		double sinus() const {
			return sin(value_ * PI / 180);
		}

		double cosinus() const {
			return cos(value_ * PI / 180);
		}
	};
}