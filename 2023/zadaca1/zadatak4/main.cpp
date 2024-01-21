#include <iostream>
#include <string>
#include <cctype>
using std::cout, std::cin, std::endl;

int main() {
	std::string str1, str2;
	cout << "Insert first word: ";
	cin >> str1;
	cout << "Insert second word: ";
	cin >> str2;
	while (str1.length() != str2.length()) {
		cout << "Strings must have equal length. Try again.\n"
			 << "Insert first word: ";
		cin >> str1;
		cout << "Insert second word: ";
		cin >> str2;
	}
	auto counter = 0;
	for (auto i = 0; i < str1.size(); i++) {
		str1[i] = std::tolower(str1[i]);
		str2[i] = std::tolower(str2[i]);
		if (str1[i] == str2[i]) counter++;
	}
	cout << "Hamming distance: " << str1.size() - counter << endl;
	return 0;
}