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

int main() {
	using std::string, std::cout, std::cin, std::endl;
	string name;
	cout << "Unesite ime: ";
	cin >> name;
	int n;
	cout << "Unesite dimenziju okvira: ";
	cin >> n;
	const string border = string(n, '*');
	const string blank = string(n, ' ');
	const string greeting = blank + string("Pozdrav ") + name + string("!") + blank;
	auto len = greeting.length();
	const string full_line = string(len + 2 * n, '*');
	const string half_line = border + string(len, ' ') + border;
	for (int i = 0; i < n; i++)
		cout << full_line << endl;
	for (int i = 0; i < n; i++)
		cout << half_line << endl;
	cout << border + greeting + border << endl;
	for (int i = 0; i < n; i++)
		cout << half_line << endl;
	for (int i = 0; i < n; i++)
		cout << full_line << endl;
	return 0;
}