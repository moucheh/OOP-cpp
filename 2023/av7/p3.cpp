// Napisati program koji trazi od korisnika unos rijeci.
// Korisnik prekida unos kada unese EOF karakter.
// Nakon unesenih rijeci program ispisuje frekvenciju ponavljanja
// svake od unesenih rijeci.
//
// Program rijesiti koristeci std::map.
//
// Primjer:
//     Unesite rijeci:
//     hi
//     jedan
//     hi
//     dva
//     dva
//     tri
//     hi
//     vjezbe
//     vjezbe
//
//     Frekvencija ponavljanja:
//     dva: 2
//     hi: 3
//     jedan: 1
//     tri: 1
//     vjezbe: 2
//
// Nakon dobijenog ispisa iznad, izvuci sve kljuceve mape u vektor
// koristeci std::transform iz algorithm zaglavlja te ispisati
// sadrzaj vektora na ekran.

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using std::cout, std::cin, std::endl;

int main() {
	std::map<std::string, int> words;
	cout << "Unesite rijeci:\n";
	for (
		std::string input;
		cin >> input;
		words[input]++
		/*
			svaki put kada pokusamo dohvatiti kljuc
			iz mape koji ne postoji
			kreira se novi, a polje vrijednosti se
			inicijalizira na default vrijednost

			svaki put kada se pojavi ista rijec
			brojac se poveca jer
			izraz words[input]++
			vraca std::pair<string, int>.second
			te se inkrementira
		*/
	);
	cout << "Frekvencija ponavljanja rijeci:\n";
	std::vector<std::string> keys;
	std::transform(
		words.begin(),
		words.end(),
		std::back_inserter(keys),
	[](std::pair<std::string, int> el) {
		return el.first;
	});
	/*
		u ovom primjeru funckija transform iz zaglavlja
		algorithm, uzima iterator na pocetak i kraj mape
		std::back_inserter na vektor u koji smjestamo
		kljuceve, te lambda funkciju koja vraca
		std::pair<std::string, int>.first
		odnosno kljuc koji je string
		i ubacuje ga u vektor stringova
	*/
	for (const auto& [word, count] : words) {
		cout << word << ": " << count << '\n';
	}
	cout << "Keys: ";
	for (const auto& key : keys) {
		cout << '"' << key << "\" ";
	}
	cout << endl;
	return 0;
}

