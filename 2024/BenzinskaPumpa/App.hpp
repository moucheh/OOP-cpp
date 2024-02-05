#pragma once
#include "BenzinskaPumpa.hpp"
#include <string>
#include <vector>
#include <stdexcept>

class App {
public:
	std::vector<BenzinskaPumpa> pretrazi(const std::string& grad) const;
	BenzinskaPumpa najjeftinija() const;
	BenzinskaPumpa najjeftinija_grad(const std::string& grad) const;
	BenzinskaPumpa najjeftinija(const std::string& tip_goriva) const;
	void ispisiPumpu();
	void dodajPumpu(const BenzinskaPumpa& p);
	void obrisiPumpu(const std::string& ime, const std::string& grad);
	~App() { pumpe.clear(); }
private:
	std::vector<BenzinskaPumpa> pumpe;
};