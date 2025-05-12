// Napisati program koji trazi unos broja od korisnika te
// ispisuje da li je broj paran ili neparan.

#include <iostream>

int main() {
	using std::cout, std::cin;
	cout << "Unesite neki broj: ";
	int num;
	cin >> num;
	if (num % 2) {
		cout << "Broj je neparan!\n";
	} else {
		cout << "Broj je paran!\n";
	}
	return 0;
}
