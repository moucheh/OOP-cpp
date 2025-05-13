#include "BenzinskaPumpa.hpp"
#include <iostream>

BenzinskaPumpa::BenzinskaPumpa(const BenzinskaPumpa& druga)
	: _ime{druga._ime},
	  _grad{druga._grad},
	  _adresa{druga._adresa}, _dizel{druga._dizel},
	  _benzin{druga._benzin},
	  _lpg{druga._lpg} {}

BenzinskaPumpa& BenzinskaPumpa::operator=(const BenzinskaPumpa& druga) {
	_ime = druga._ime;
	_grad = druga._grad;
	_adresa = druga._adresa;
	_dizel = druga._dizel;
	_benzin = druga._benzin;
	_lpg = druga._lpg;
	return *this;
}


BenzinskaPumpa::BenzinskaPumpa(BenzinskaPumpa&& druga)
	: _ime{std::move(druga._ime)},
	  _grad{std::move(druga._grad)},
	  _adresa{std::move(druga._adresa)},
	  _dizel{druga._dizel},
	  _benzin{druga._benzin},
	  _lpg{druga._lpg} {}

BenzinskaPumpa::BenzinskaPumpa(
	const std::string& ime,
	const std::string& grad,
	const std::string& adresa
) :
	_ime{ime},
	_grad{grad},
	_adresa{adresa} {}

void BenzinskaPumpa::postaviCijene(
	const double& dizel,
	const double& benzin,
	const double& lpg
) {
	_dizel = dizel;
	_benzin = benzin;
	_lpg = lpg;
}


void BenzinskaPumpa::ispisiPumpu() const {
	std::cout << "Ime: " << _ime
			  << "\nGrad: " << _grad
			  << "\nAdresa: " << _adresa
			  << "\nDizel: " << _dizel
			  << "\nBenzin: " << _benzin
			  << "\nlpg: " << _lpg << "\n\n";
}