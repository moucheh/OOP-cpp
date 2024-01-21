// Napisati program koji trazi od korisnika unos rijeci.
// Korisnik prekida unos kada unese EOF karakter.
// Nakon unesenih rijeci program ispisuje frekvenciju ponavljanja
// svake od unesenih rijeci.
//
// Program rijesiti koristeci vektore, std::sort i strukture.
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
//     hi: 3
//     jedan: 1
//     dva: 2
//     tri: 1
//     vjezbe: 2
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using std::cout, std::cin, std::endl;
using std::string, std::vector;

struct WordCount {
	string Word;
	int Counter;
};

int main() {
	vector<string> words;
	string input;
	cout << "Unesite rijeci:\n";
	while (cin >> input) {
		words.push_back(input);
	}
	std::sort(words.begin(), words.end());
	vector<WordCount> result;
	string prev;
	for (const auto& word : words) {
		if (word != prev) {
			WordCount wc;
			wc.Word = word;
			wc.Counter = 1;
			result.push_back(wc);
			/*
				slicna pjesma kao p2 iz av5
				u prvoj iteraciji se provjerava
				da li je prethodna rijec ista kao trenutna
				u sustini ovo ce uvijek okinut kao tacno u prvoj iteraciji
				pravi se objekat, u njega se sprema rijec i inicijalizira
				brojac na 1, jer vec imamo prvu rijec
				te se dodaje na kraj vektora result

				svaki put kad se naidje na novu rijec pravi se novi objekat
				(tipa WordCount) i dodaje na kraj vektora
			*/
		} else {
			result.back().Counter++;
			/*
				ako je trenutna rijec ista kao prethodna,
				povecavamo brojac za 1
			*/
		}
		prev = word; // na kraju svake iteracije trenutna rijec postaje prethodna
	}
	cout << "Frekvencija ponavljanje:" << endl;
	for (const auto& i : result) {
		cout << i.Word << ": " << i.Counter << endl;
	}
	return 0;
}