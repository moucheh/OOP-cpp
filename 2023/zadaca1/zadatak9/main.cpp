#include <iostream>
#include <string>
#include <vector>
using std::cout, std::cin, std::endl, std::vector, std::string;

int main() {
	vector<string> words;
	string input;
	cout << "Unesi rijec: ";
	std::getline(cin, input);
	while (input.length() != 0) {
		words.push_back(input);
		cout << "Unesi rijec: ";
		std::getline(cin, input);
	}
	int len = 1;
	int index;
	int sum = 0;
	for (int i = 0; i < words.size(); i++) {
		if (words[i].length() > len) {
			len = words[i].length();
			index = i;
		}
		sum += words[i].length();
	}
	const string hline = string(50, '=');
	const string full_line = string(len + 4, '+');
	const string blank = string("+ ") + string(len, ' ') + string(" +");
	cout << hline << endl
		 << "Lista rijeci" << endl;
	for (const auto& word : words) cout << word << " ";
	cout << endl << "Ukupan broj karaktera: " << sum << endl
		 << hline << endl
		 << "Najduza rijec" << endl
		 << full_line << endl
		 << blank << endl
		 << "+ " << words[index] << " +" << endl
		 << blank << endl
		 << full_line << endl;
	return 0;
}