// Napisati program koji trazi od korisnika unos broja
// te ukoliko je broj djeljiv sa 3 na ekranu ispisuje Fizz,
// ukoliko je broj djeljiv sa 5 na ekranu ispisuje Buzz
// te ukoliko je broj djeljiv i sa 3 i sa 5, na ekranu se
// ispisuje FizzBuzz. Program se terminira kada korisnik
// unese 0.
#include <iostream>

int main() {
	using std::cout, std::cin;
	cout << "Unesite neki broj: ";
	int n;
	cin >> n;
	while (n != 0) {
		if (n % 3 == 0) {
			cout << "Fizz";
		}
		if (n % 5 == 0) {
			cout << "Buzz";
		}
		cout << "\nPonovite unos: ";
		cin >> n;
	}
	return 0;
}
