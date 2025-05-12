// Napisati funkciju filter koja treba da isfiltrira proslijedjeni
// vektor na nacin da kopira elemente proslijedjenog vektora koji
// zadovoljavaju dati predicate. Ukoliko je proslijedjena nevalidna
// predicate funkcija, potrebno je baciti iznimku tipa:
//    std::logic_error
//
// Nakon toga, dodati jos jednu (overloaded) funkciju filter koja
// uzima vektor i string te kopira sve stringove koji odgovaraju
// datom argumentu u rezultujuci vektor.

#include <iostream>
#include <vector>

template<typename vec_str_it, typename func>
std::vector<std::string> filter(
	vec_str_it begin,
	vec_str_it end,
	func predicate
) {
	std::vector<std::string> result;
	for (; begin != end; ++begin)
		if (predicate(*begin))
			result.push_back(*begin);
	return result;
}

int main() {
	std::vector<std::string> vec;
	std::string s;
	std::cout << "Unesite rijeci: " << std::endl;
	while (std::cin >> s) {
		vec.push_back(s);
	}
	auto filtered = filter(vec.begin(), vec.end(),
	[](const std::string & s) {
		return s.size() > 5;
	});
	std::cout << "Result: " << std::endl;
	for (const auto& el : filtered) {
		std::cout << el << std::endl;
	}
	return 0;
}
