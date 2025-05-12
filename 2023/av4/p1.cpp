// Napisati program koji trazi od korisnika unos imena,
// a zatim na ekran ispisuje uokvireno ime sa praznim prostorom
// sirine 2 karaktera.
//
// Primjer:
//
// Unesite ime: Mirza
// **********************
// **********************
// **                  **
// **                  **
// **  Pozdrav Mirza!  **
// **                  **
// **                  **
// **********************
// **********************
//

#include <iostream>
using std::cout, std::cin;

int main() {
	using std::string;
	string name;
	cout << "Unesite ime: ";
	cin >> name;
	const string greeting = string("**  Pozdrav ") + name + string("!  **\n");
	short len = greeting.length() - 1;
	const string stars = string(len, '*') + string("\n");
	const string blank = string("**") + string(len - 4, ' ') + string("**\n");
	cout << stars
		 << stars
		 << blank
		 << blank
		 << greeting
		 << blank
		 << blank
		 << stars
		 << stars;
	return 0;
}

