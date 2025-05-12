#include <iostream>
using std::cout, std::cin, std::endl;

template<typename it1, typename it2>
bool jednako(it1 od1, it1 do1, it2 od2) {
	for (; od1 != do1; ++od1) {
		if (*od1 != *od2)
			return false;
		++od2;
	}
	return true;
}

int main() {
	std::string ime = "Hole";
	bool palindrom = jednako(ime.begin(), ime.end(), ime.rbegin());
	cout << ((palindrom) ? "Palindrom" : "Nije palindrom") << endl;
	return 0;
}