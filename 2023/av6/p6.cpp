#include <iostream>
#include <vector>
#include <stdexcept>

int main() {
	std::vector<std::string> vek{"dva", "elementa"};
	try {
		auto elem = vek.at(2);
		/*
			metoda .at(broj) nad nekim kontejnerom
			radi indeksiranje, te ukoliko ne postoji
			element pod tim indeksom baca
			std::out_of_range exception iz stdexcept
			zaglavlja, posto vektor ima dva elementa
			a mi trazimo treci, to ce se upravo i desiti
			u ovom primjeru
		*/
	} catch (std::invalid_argument& err) {
		/*
			ovaj blok se preskace, jer ovaj primjer
			ne baca invalid_argument exception
		*/
		std::cout << "Invalid argument caught: " << err.what() << std::endl;
	} catch (std::out_of_range& err) {
		std::cout << "Out of range caught: " << err.what() << std::endl;
		/*
			kada uhvatimo iznimku, mozemo je smjestiti u neku varijablu
			te iz nje citati neke debug informacije koje mogu biti korisne
			err.what() =
			"vector::_M_range_check: __n (which is 2) >= this->size() (which is 2)"
			sto znaci da je index 2 veci od broja elemenata naseg vektora
		*/
	}
	return 0;
}
