#include "Radnik.hpp"

bool daLiPostojiRadnik(const std::list<Radnik>& radnici, const std::string& ime) {
	for (const auto& radnik : radnici)
		if (radnik.ime == ime) {
			throw std::domain_error{"Radnik vec u bazi."};
			return true;
		}
	return false;
}
