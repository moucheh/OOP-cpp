// Napisati funkciju copy_if koja uzima 4 parametra:
// 1. pocetak sekvence
// 2. kraj sekvence
// 3. destinacija
// 4. predicate funkcija
//
// copy_if treba da kopira elemente koji zadovoljavaju predicate funkciju
// ulazne sekvence na destinaciju. Funkcija treba da radi za razlicite tipove
// kontejnera.


#include <iostream>
#include <vector>
#include <list>

int main() {
	std::vector<int> vint{1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> parni;
	// pozvati copy_if
	std::cout << "Parni: " << std::endl;
	for (int n : parni) {
		std::cout << n << ' ';
	}
	std::cout << std::endl;
	std::list<int> lint{1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::list<int> neparni;
	// pozvati copy_if
	std::cout << "Neparni: " << std::endl;
	for (int n : neparni) {
		std::cout << n << ' ';
	}
	std::cout << std::endl;
	std::list<std::string> lstr{"hello", "auto", "world", "ant", "all", "exercise"};
	std::list<std::string> stringovi_sa_a;
	// pozvati copy_if
	std::cout << "Stringovi koji pocinju sa a u obrnutom redoslijedu: " << std::endl;
	for (int n : neparni) {
		std::cout << n << ' ';
	}
	std::cout << std::endl;
	return 0;
}
