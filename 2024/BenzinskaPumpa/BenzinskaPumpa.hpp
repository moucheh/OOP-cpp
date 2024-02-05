#pragma once
#include <string>

class BenzinskaPumpa {
public:
	friend class App;
	BenzinskaPumpa() = delete;

	BenzinskaPumpa(const BenzinskaPumpa& druga);
	BenzinskaPumpa(BenzinskaPumpa&& druga);

	BenzinskaPumpa& operator=(const BenzinskaPumpa& druga);

	BenzinskaPumpa(
		const std::string& ime,
		const std::string& grad,
		const std::string& adresa
	);

	void postaviCijene(
		const double& dizel,
		const double& benzin,
		const double& lpg
	);

	bool operator<(const BenzinskaPumpa& druga) const {
		return _dizel < druga._dizel &&
			   _benzin < druga._benzin &&
			   _lpg < druga._lpg;
	}

	void ispisiPumpu() const;
private:
	std::string _ime;
	std::string _grad;
	std::string _adresa;
	double _dizel{};
	double _benzin{};
	double _lpg{};
};