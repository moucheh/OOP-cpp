#include "Handler.hpp"

std::string provjera2(
	const std::vector<Handler>& hs,
	const std::string& _id,
	const int a,
	const int b
) {
	std::string result;
	for (const auto& h : hs) {
		if (h.id == _id) {
			result += h.foo(a, b) + "; ";
		}
	}
	return result;
}