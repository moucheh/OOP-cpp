#include "App.hpp"

std::vector<BenzinskaPumpa> App::pretrazi(const std::string& grad) const {
	std::vector<BenzinskaPumpa> result;
	for (const auto& pumpa : pumpe)
		if (pumpa._grad == grad)
			result.push_back(pumpa);
	if (!result.size())
		throw std::invalid_argument{
		std::string("Nije pronadjena ni jedna benzinska pumpa u gradu: ") + grad
	};
	return result;
}

void App::dodajPumpu(const BenzinskaPumpa& p) {
	pumpe.push_back(p);
}

BenzinskaPumpa App::najjeftinija() const {
	auto min = pumpe.back();
	for (const auto& pumpa : pumpe)
		if (pumpa < min) {
			min = pumpa;
		}
	return min;
}

BenzinskaPumpa App::najjeftinija_grad(const std::string& grad) const {
	auto pumpeIzGrada = pretrazi(grad);
	auto min = pumpeIzGrada.front();
	for (const auto& pumpa : pumpeIzGrada)
		if (pumpa < min)
			min = pumpa;
	return min;
}

BenzinskaPumpa App::najjeftinija(const std::string& tip_goriva) const {
	if (
		tip_goriva != "dizel" &&
		tip_goriva != "benzin" &&
		tip_goriva != "lpg"
	) throw std::invalid_argument("Navedeni tip goriva nije trenutno u ponudi.");
	auto min = pumpe.front();
	if (tip_goriva == "dizel") {
		for (const auto& pumpa : pumpe)
			if (pumpa._dizel < min._dizel)
				min = pumpa;
	} else if (tip_goriva == "benzin") {
		for (const auto& pumpa : pumpe)
			if (pumpa._benzin < min._benzin)
				min = pumpa;
	} else if (tip_goriva == "lpg") {
		for (const auto& pumpa : pumpe)
			if (pumpa._lpg < min._lpg)
				min = pumpa;
	}
	return min;
}

void App::obrisiPumpu(const std::string& ime, const std::string& grad) {
	auto it = pumpe.cend();
	for (auto i = pumpe.cbegin(); i != pumpe.cend(); ++i)
		if (i->_ime == ime && i->_grad == grad)
			it = i;
	if (it == pumpe.cend()) return;
	pumpe.erase(it);
}
