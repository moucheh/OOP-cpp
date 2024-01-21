// Napisati program koji trazi od korisnika unos rijeci
// te ispisuje unesene rijeci sortirane od Z -> A.

#include <iostream>
#include <algorithm>
#include <vector>

using std::cout, std::cin, std::endl;
using std::string;

int main() {
	std::vector<string> words;
	string word;
	cout << "Unesite rijeci: " << endl;
	while (cin >> word) {
		words.push_back(word);
	}
	auto criterium = [](const string & a,  const string & b) {
		return a > b;
	};
	std::sort(words.begin(), words.end(), criterium);
	cout << "Sortirane rijeci:\n";
	for (const auto& word : words) {
		cout << word << endl;
	}
	return 0;
}
