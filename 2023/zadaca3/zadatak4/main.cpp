#include "Student.hpp"
#include "Helpers.hpp"

int main() {
	std::list<Predmet> predmeti{};
	std::list<Student> studenti{};
	int izbor = menu();
	while (true) {
		if (izbor == 1) {
			unesi_predmet(predmeti);
			izbor = menu();
		} else if (izbor == 2) {
			unesi_studenta(studenti, predmeti);
			izbor = menu();
		} else if (izbor == 3) {
			edituj_studenta(predmeti, studenti);
			izbor = menu();
		} else if (izbor == 4) {
			ispisi_studente(studenti);
			izbor = menu();
		} else break;
	}
	return 0;
}