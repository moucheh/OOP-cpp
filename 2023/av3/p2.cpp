// Napisati program koji trazi unos broja od korisnika te
// ispisuje da li je broj paran ili neparan.

#include <iostream>
using namespace std;

int main() {
	cout << "Unesite broj: ";
	int a;
	cin >> a;
	if (a & 1)
		cout << "Broj je neparan." << endl;
	else
		cout << "Broj je paran." << endl;
	return 0;
}