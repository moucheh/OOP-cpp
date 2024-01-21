// Napisati program koji trazi od korisnika unos rijeci.
// Korisnik prekida unos kada unese EOF karakter.
// Nakon unesenih rijeci program ispisuje frekvenciju ponavljanja
// svake od unesenih rijeci.
//
// Program rijesiti koristeci vektore i std::sort.
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

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout, std::cin, std::endl;
using std::vector, std::string;
using group = vector<string>;
using group_of_groups = vector<group>;

void make_word_groups(const group& w, group_of_groups& g) {
	string prev;
	for (auto i = 0; i < w.size(); i++) {
		if (w[i] != prev) {
			g.push_back(group{w[i]});
			/*
				u prvoj iteraciji petlje u uslovu se
				provjerava da li je rijec ista kao prethodna
				u ovom slucaju je to prazan string,
				te se uvijek evaluira kao tacno
				stoga se ubacuje jedna grupa (vektor stringova)
				u vektor grupa
				copy konstrukcijom inicijalizirana
				sa rijecju iz trenutne iteracije (w[i])

				u prevodu g[0][0] = w[i]

				svaki put kada se naidje na novu rijec,
				pravi se grupa (vektor stringova) i
				dodaje na kraj vektora grupa
			*/
		} else {
			g.back().push_back(w[i]);
			/*
				u drugoj iteraciji gleda se posljednji element
				vektora grupa, u ovom slucaju je to
				jedini element i dodaje rijec se element na kraj

				sve dok je ista rijec ona se dodaje
				u istu grupu (vektor stringova)
			*/
		}
		prev = w[i]; // trenutna rijec postaje prethodna rijec
	}
}

int main() {
	cout << "Unesite rijeci:\n";
	group words;
	string input;
	while (cin >> input) {
		words.push_back(input);
	}
	group_of_groups gog;
	std::sort(words.begin(), words.end()); //vektor se prvo sortira leksikografski
	make_word_groups(words, gog);
	cout << "Frekvencija ponavljanja:\n";
	for (const auto& r : gog) {
		cout << r.front()
			 << ": "
			 << r.size()
			 << endl;
	}
	return 0;
}
