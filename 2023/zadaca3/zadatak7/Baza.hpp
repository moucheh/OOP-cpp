#pragma once
#include <string>
#include <list>
#include "Radnik.hpp"
#include <iostream>

struct BazaRadnika {
	std::list<Radnik> radnici;
	void ucitaj(std::istream&);
	bool izbrisi_radnika(const std::string&);
	void ispisi(std::ostream& izlaz) const;
	double prosjek_plata() const;
	double prosjek_godina() const;
};