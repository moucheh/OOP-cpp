#pragma once

#include <cmath>

namespace Complex {
	class Radian {
	private:
		double value_;
	public:
		explicit Radian(double value)
			: value_{value} {}

		double getValue() const {
			return value_;
		}

		void setValue(double value) {
			value_ = value;
		}

		double sinus() const {
			return sin(value_);
		}

		double cosinus() const {
			return cos(value_);
		}
	};
}