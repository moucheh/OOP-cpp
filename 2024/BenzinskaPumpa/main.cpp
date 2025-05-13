#include <iostream>
#include "BenzinskaPumpa.hpp"
#include "App.hpp"
using std::cout, std::cin, std::endl;

int main() {
	App a;
	BenzinskaPumpa b1{"Kopex Sarajlic", "Srebrenik", "adresa1"};
	b1.postaviCijene(1, 2, 3);
	a.dodajPumpu(b1);
	BenzinskaPumpa b2{"Hifa Petrol", "Gradacac", "adresa2"};
	b2.postaviCijene(4, 5, 6);
	a.dodajPumpu(b2);
	BenzinskaPumpa b3{"Hifa Oil", "Gradacac", "adresa3"};
	b3.postaviCijene(2, 4, 4);
	a.dodajPumpu(b3);
	BenzinskaPumpa b4{"EnergoPetrol", "Gradacac", "adresa4"};
	b4.postaviCijene(4, 3, 0.8);
	a.dodajPumpu(b4);
	BenzinskaPumpa b5{"Gazprom", "Tuzla", "adresa5"};
	b5.postaviCijene(1, 1, 1);
	a.dodajPumpu(b5);
	a.obrisiPumpu("Gazprom", "Tuzla");
	a.najjeftinija().ispisiPumpu();
	a.najjeftinija_grad("Gradacac").ispisiPumpu();
	a.najjeftinija("lpg").ispisiPumpu();
	return 0;
}