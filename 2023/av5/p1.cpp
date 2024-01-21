// Napisati program koji od korisnika trazi unos rijeci.
// Nakon toga unesenu rijec ispisuje na satrovackom. :)
//
// Primjer:
// Unesite rijec: nemoj
// mojne
//
// Unesite rijec: zdravo
// vozdra

#include <iostream>
#include <string>
using std::cout, std::cin, std::endl;

int main() {
	using std::string;
	std::string word;
	cout << "Unesite rijec: ";
	cin >> word;
	string res;
	string::iterator index_of_first_vowel;
	for (string::iterator it = word.begin(); it != word.end(); ++it) {
		if (
			*it == 'a' ||
			*it == 'e' ||
			*it == 'i' ||
			*it == 'o' ||
			*it == 'u'
		) {
			index_of_first_vowel = it;
			break;
		}
	}
	for (string::iterator it = index_of_first_vowel + 1; it != word.end(); ++it) {
		res.push_back(*it);
	}
	for (string::iterator it = word.begin(); it != index_of_first_vowel + 1; ++it) {
		res.push_back(*it);
	}
	cout << res << endl;
	return 0;
}