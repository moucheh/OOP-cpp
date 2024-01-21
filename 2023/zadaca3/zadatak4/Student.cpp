#include "Student.hpp"
#include "Helpers.hpp"

using std::cout, std::cin, std::endl;
using std::list, std::vector, std::getline;
using std::string;

int unesi_ocjenu() {
	int ocjena;
	cout << "Unesi ocjenu: ";
	cin >> ocjena;
	if (!cin)
		fixCin();
	if (ocjena > 5 && ocjena <= 10)
		return ocjena;
	else {
		cout << "Pogresan unos, ocjena mora biti broj izmedju 5 i 10" << endl;
		return unesi_ocjenu();
	}
}

void dodaj_ocjenu(
	const list<Predmet>& predmeti,
	Student& student
) {
	string predmet;
	cout << "Unesite predmet za koji unosite ocjenu: ";
	fixCin();
	getline(cin, predmet);
	OcjenaIzPredmeta temp;
	temp.predmet = predmeti.cend();
	for (auto it = predmeti.cbegin(); it != predmeti.cend(); ++it) {
		if (it->naziv == predmet) {
			temp.predmet = it;
		}
	}
	if (temp.predmet == predmeti.cend()) {
		throw std::invalid_argument{"Predmet ne postoji."};
	}
	temp.ocjena = unesi_ocjenu();
	student.ocjene.push_back(temp);
}

void unesi_predmet(std::list<Predmet>& predmeti) {
	Predmet predmet;
	cout << "\nUnesite naziv predmeta: ";
	fixCin();
	getline(cin, predmet.naziv);
	try {
		if (provjeri_da_li_predmet_postoji(predmeti, predmet.naziv))
			throw std::invalid_argument{"Predmet vec postoji."};
	} catch (const std::invalid_argument& e) {
		clrscr();
		cout << e.what() << endl;
		return;
	}
	cout << "Unesite odsjek predmeta: ";
	getline(cin, predmet.odsjek);
	predmeti.push_back(predmet);
}

void unesi_studenta(
	list<Student>& studenti,
	list<Predmet>& predmeti
) {
	Student student;
	cout << "\nUnesite broj indeksa studenta: ";
	cin >> student.brojIndeksa;
	try {
		if (provjeri_da_li_student_postoji(studenti, student.brojIndeksa))
			throw std::invalid_argument{"Student vec postoji."};
	} catch (const std::invalid_argument& e) {
		clrscr();
		cout << e.what() << endl;
		return;
	}
	cout << "Unesite ime studenta: ";
	fixCin();
	getline(cin, student.ime);
	cout << "Unesite prezime studenta: ";
	getline(cin, student.prezime);
	cout << "Unesite mjesto stanovanja studenta: ";
	getline(cin, student.grad);
	int n;
	cout << "\nUnesite broj ocjena koji unosite: ";
	cin >> n;
	if (!cin) {
		n = 0;
		fixCin();
	}
	try {
		for (auto i = 0; i < n; i++)
			dodaj_ocjenu(predmeti, student);
	} catch (const std::invalid_argument& e) {
		cout << e.what() << endl;
		return;
	}
	studenti.push_back(student);
}

void ispisi_studente(const std::list<Student>& studenti) {
	const string separator_unutarnji = string(30, '-');
	const string separator_vanjski = string(30, '=');
	clrscr();
	if (studenti.empty()) {
		cout << "Niste unijeli niti jednog studenta." << endl;
		return;
	}
	cout << separator_vanjski << "\nStudenti:" << endl;
	for (const auto& student : studenti) {
		cout << "\nBroj indeksa: " << student.brojIndeksa << '\n'
			 << "Ime: " << student.ime << '\n'
			 << "Prezime: " << student.prezime << '\n'
			 << "Grad: " << student.grad << '\n';
		if (student.ocjene.empty())
			continue;
		cout << "Ocjene:" << '\n'
			 << separator_unutarnji << '\n';
		auto sum = 0.;
		for (const auto& ocjena_iz_predmeta : student.ocjene) {
			cout << ocjena_iz_predmeta.predmet->naziv << ": "
				 << ocjena_iz_predmeta.ocjena << '\n';
			sum += ocjena_iz_predmeta.ocjena;
		}
		cout << separator_unutarnji << '\n'
			 << "Prosjek ocjena: "
			 << sum / student.ocjene.size() << '\n';
	}
	cout << separator_vanjski << endl;
}

void edituj_studenta(
	const list<Predmet>& predmeti,
	list<Student>& studenti
) {
	string indeks;
	cout << "\nUnesite broj indeksa: ";
	cin >> indeks;
	try {
		if (!provjeri_da_li_student_postoji(studenti, indeks)) {
			throw std::invalid_argument{"Student ne postoji."};
		}
	} catch (const std::invalid_argument& e) {
		cout << e.what() << endl;
		return;
	}
	int izbor = edit_menu();
	if (izbor == 1) {
		string novi_indeks;
		cout << "\nUnesite novi broj indeksa: ";
		cin >> novi_indeks;
		for (auto st = studenti.begin(); st != studenti.end(); ++st)
			if (st->brojIndeksa == indeks) {
				st->brojIndeksa = novi_indeks;
				return;
			}
	} else if (izbor == 2) {
		string novo_ime;
		cout << "\nUnesite novo ime studenta: ";
		fixCin();
		getline(cin, novo_ime);
		for (auto st = studenti.begin(); st != studenti.end(); ++st)
			if (st->brojIndeksa == indeks) {
				st->ime = novo_ime;
				return;
			}
	} else if (izbor == 3) {
		string novo_prezime;
		cout << "\nUnesite novo prezime studenta: ";
		fixCin();
		getline(cin, novo_prezime);
		for (auto st = studenti.begin(); st != studenti.end(); ++st)
			if (st->brojIndeksa == indeks) {
				st->prezime = novo_prezime;
				return;
			}
	} else if (izbor == 4) {
		string novi_grad;
		cout << "\nUnesite novo mjesto stanovanja studenta: ";
		fixCin();
		getline(cin, novi_grad);
		for (auto st = studenti.begin(); st != studenti.end(); ++st)
			if (st->brojIndeksa == indeks) {
				st->grad = novi_grad;
				return;
			}
	} else if (izbor == 5) {
		cout << "Obrisali ste ocjene studenta." << endl;
		vector<OcjenaIzPredmeta> ocjene{};
		for (auto st = studenti.begin(); st != studenti.end(); ++st)
			if (st->brojIndeksa == indeks) {
				st->ocjene = ocjene;
				return;
			}
	} else if (izbor == 6) {
		auto st = studenti.begin();
		for (; st != studenti.end(); ++st) {
			if (st->brojIndeksa == indeks) break;
		}
		try {
			dodaj_ocjenu(predmeti, *st);
		} catch (const std::invalid_argument& e) {
			cout << e.what() << endl;
			return;
		}
	} else if (izbor == 7) { return; }
}