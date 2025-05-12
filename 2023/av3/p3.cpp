// Napisati program koji trazi od korisnika unos broja
// te ukoliko je broj djeljiv sa 3 na ekranu ispisuje Fizz,
// ukoliko je broj djeljiv sa 5 na ekranu ispisuje Buzz
// te ukoliko je broj djeljiv i sa 3 i sa 5, na ekranu se
// ispisuje FizzBuzz. Program se terminira kada korisnik
// unese 0.

#include <iostream>

int main() {
	using std::cout, std::cin, std::endl;
	int input;
	do {
		cout << "Unesite neki broj: ";
		cin >> input;
		if (input == 0) break;
		if (input % 3 == 0) cout << "Fizz";
		if (input % 5 == 0) cout << "Buzz";
		cout << endl;
	} while (input);
	return 0;
}