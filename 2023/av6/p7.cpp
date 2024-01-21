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
#include <stdexcept>
#include <functional>

using std::cout, std::cin, std::endl;
using std::string, std::vector;

vector<string> filter(
	const vector<string>& words,
	std::function<bool(const string&)> predicate
) {
	vector<string> result;
	for (const auto& word : words) {
		try {
			if (predicate(word))
				result.push_back(word);
		} catch (std::logic_error e) {
			result = words;
			cout << e.what() << endl;
			cout << "Funckija vraca isti originalni kontejner." << endl;
			return result;
		}
	}
	return result;
}

vector<string> filter(const vector<string>& words, const string& str) {
	vector<string> result;
	for (const auto& word : words) {
		if (word.find(str) != string::npos)
			result.push_back(word);
	}
	return result;
	/*
		ova funckija vraca filtriran vektor rijeci
		tako da svaka rijec sadrzi u sebi proslijedjenu rijec str
	*/
}

int main() {
	vector<string> words;
	string input;
	cout << "Unesite rijeci: " << endl;
	while (cin >> input) {
		words.push_back(input);
	}
	auto filtered = filter(words, [](const string & str) {
		if (str.size() > 15)
			throw std::logic_error{"Unijeli ste predugu rijec."};
		return str.size() > 5;
		//izraz vraca tacno ukoliko je duzina rijeci veca od 5
	});
	cout << "Filtriran vektor:\n";
	for (const auto& word : filtered) {
		cout << word << endl;
	}
	return 0;
}
