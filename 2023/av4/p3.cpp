// Napisati program koji od korisnika trazi unos broja recenica.
// Nakon toga korisnik unosi onoliko recenica koliko je naveo,
// te program ispisuje prosjecnu duzinu unesenih recenica.
//
// Primjer:
// Unesite broj recenica: 3
// Unesite recenicu (1/3): Hello world
// Unesite recenicu (2/3): Danas je srijeda
// Unesite recenicu (3/3): Hi
// Prosjecna duzina recenica: 9.66667

#include <iostream>
#include <vector>
#include <string>
#include <limits>
using std::cout, std::cin, std::endl;

int main() {
	std::vector<std::string> sentences;
	std::string input;
	int n;
	cout << "Unesite broj recenica: ";
	cin >> n;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	auto sum = 0.;
	for (auto i = 0; i < n; i++) {
		cout << "Unesite recenicu (" << i + 1 << "/" << n << "): ";
		std::getline(cin, input);
		sentences.push_back(input);
		sum += input.length();
	}
	cout << "Prosjecna duzina recenica: " << sum / n << endl;
	cout << "Korisnik je unio recenice: " << endl;
	for (const auto& sent : sentences) cout << sent << endl;
	return 0;
}