#include "Baza.hpp"
using std::cout, std::endl;

void BazaRadnika::ucitaj(std::istream& ulaz) {
	Radnik radnik;
	while (ulaz >> radnik.ime >> radnik.plata >> radnik.godine) {
		try {
			if (!daLiPostojiRadnik(radnici, radnik.ime))
				radnici.push_back(radnik);
		} catch (const std::domain_error& e) {
			cout << e.what() << endl;
		}
	}
}

bool BazaRadnika::izbrisi_radnika(const std::string& ime) {
	auto it = radnici.cbegin();
	for (; it != radnici.cend(); ++it) {
		if (it->ime == ime) break;
	}
	if (it == radnici.cend()) return false;
	radnici.erase(it);
	return true;
}

void BazaRadnika::ispisi(std::ostream& izlaz) const {
	for (const auto& radnik : radnici)
		izlaz << radnik.ime << ' ' << radnik.plata << ' ' << radnik.godine << '\n';
	izlaz << endl;
}

double BazaRadnika::prosjek_plata() const {
	auto sum = 0.;
	for (const auto& radnik : radnici)
		sum += radnik.plata;
	return sum / radnici.size();
}

double BazaRadnika::prosjek_godina() const {
	auto sum = 0.;
	for (const auto& radnik : radnici)
		sum += radnik.godine;
	return sum / radnici.size();
}