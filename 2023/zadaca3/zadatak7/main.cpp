#include <iostream>
#include "Baza.hpp"
using std::cout, std::cin, std::endl;

int main() {
	BazaRadnika b1;
	b1.ucitaj(cin);
	if (b1.izbrisi_radnika("alen")) {
		cout << "alen izbrisan" << endl;
	} else {
		cout << "Brisanje nije moguce!" << endl;
	}
	cout << "U bazi su: " << endl;
	b1.ispisi(cout);
	cout << "Prosjek plata je: " << b1.prosjek_plata() << endl;
	cout << "Prosjek godina je: " << b1.prosjek_godina() << endl;
	return 0;
}