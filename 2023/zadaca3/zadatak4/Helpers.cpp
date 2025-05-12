#include "Helpers.hpp"
#include "Student.hpp"

#if _WIN32

void clrscr() { system("cls"); }

#else

void clrscr() { system("clear"); }

#endif

using std::cout, std::cin, std::endl;


void fixCin() {
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

const int unesi_izbor(const int broj_izbora) {
	int izbor;
	cin >> izbor;
	if (!cin)
		fixCin();
	if (izbor > 0 && izbor <= broj_izbora)
		return izbor;
	else {
		cout << "Pogresan unos, izbor mora biti broj izmedju 1 i " << broj_izbora << '!' << endl;
		return unesi_izbor(broj_izbora);
	}
}

int menu() {
	cout << "\nUnesite opciju:\n"
		 << "1. Dodaj predmet\n"
		 << "2. Dodaj studenta\n"
		 << "3. Edituj studenta\n"
		 << "4. Ispisi studente\n"
		 << "5. Izlaz iz programa\n"
		 << "Izbor: ";
	int izbor = unesi_izbor(5);
	return izbor;
}

int edit_menu() {
	cout << "\nUnesite opciju:\n"
		 << "1. Mijenjanje broja indeksa studenta\n"
		 << "2. Mijenjanje imena studenta\n"
		 << "3. Mijanjanje prezimena studenta\n"
		 << "4. Mijenjanje grada studenta\n"
		 << "5. Brisanje svih ocjena\n"
		 << "6. Dodavanje novih ocjena\n"
		 << "7. Nazad\n"
		 << "Izbor: ";
	int izbor = unesi_izbor(7);
	return izbor;
}

bool provjeri_da_li_predmet_postoji(
	const std::list<Predmet>& predmeti,
	const std::string& naziv
) {
	for (const auto& predmet : predmeti)
		if (predmet.naziv == naziv)
			return true;
	return false;
}

bool provjeri_da_li_student_postoji(
	const std::list<Student>& studenti,
	const std::string& indeks
) {
	for (const auto& student : studenti)
		if (student.brojIndeksa == indeks)
			return true;
	return false;
}