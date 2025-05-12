// Napisati funkciju koja uzima vektor stringova te
// ga transformise na nacin da provjerava da li string
// zavrsava nekim od znakova interpunkcije koji oznacava
// kraj recenice (? ! ili .). Ukoliko string ne zavrsava
// nekim od znakova interpunkcije, dodati tacku na kraj
// stringa.
//

#include <iostream>
#include <vector>

typedef std::vector<std::string> v_s;

void add_interpunction(v_s& vec) {
	for (auto& i : vec) {
		if (
			i.back() == '.' ||
			i.back() == '?' ||
			i.back() == '!'
		)
			continue;
		i.push_back('.');
	}
}


int main() {
	std::vector<std::string> vec;
	std::string input;
	while (std::getline(std::cin, input)) {
		vec.push_back(input);
	}
	add_interpunction(vec);
	std::cout << "Elementi kontejnera su:\n";
	for (const auto& i : vec) {
		std::cout << i << std::endl;
	}
	return 0;
}
