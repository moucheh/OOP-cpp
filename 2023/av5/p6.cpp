// Napisati funkciju koja uzima vektor stringova te
// ga transformise na nacin da provjerava da li string
// zavrsava nekim od znakova interpunkcije koji oznacava
// kraj recenice (? ! ili .). Ukoliko string ne zavrsava
// nekim od znakova interpunkcije, dodati tacku na kraj
// stringa.
//

#include <iostream>
#include <vector>

using std::cout, std::cin, std::endl;
using std::vector, std::string;

void add_interpunction(vector<string>& vec) {
	for (auto& i : vec) {
		if (
			i.back() == '?' ||
			i.back() == '!' ||
			i.back() == '.'
		) continue;
		i.push_back('.');
	}
}

int main() {
	vector<string> vec;
	string input;
	cout << "Unesite recenice:\n";
	while (std::getline(cin, input)) {
		vec.push_back(input);
	}
	add_interpunction(vec);
	cout << "Transformisane recenice:\n";
	for (const auto& i : vec) {
		cout << i << endl;
	}
	return 0;
}
