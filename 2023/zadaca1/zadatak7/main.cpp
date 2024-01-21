#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::cout, std::cin, std::endl, std::vector, std::string;

int main() {
	vector<string> words;
	string input;
	cout << "Unesi rijec: ";
	std::getline(cin, input);
	while (!input.empty()) {
		words.push_back(input);
		cout << "Unesi rijec: ";
		std::getline(cin, input);
	}
	std::sort(words.begin(), words.end());
	int len = 1;
	for (const auto& word : words) {
		if (word.length() > len) len = word.length();
	}
	const string full_line = string(len + 4, '+');
	const string blank = string("+ ") + string(len, ' ') + string(" +");
	auto printWord = [len](string w) {
		return string("+ ") + w + string(len - w.length(), ' ') + string(" +");
	};
	cout << full_line
		 << endl
		 << blank
		 << endl;
	for (const auto& word : words)
		cout << printWord(word) << endl;
	cout << blank
		 << endl
		 << full_line
		 << endl;
	return 0;
}