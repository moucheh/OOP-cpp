// Napisati program koji trazi od korisnika unos brojeva.
// Unos se zavrsava kada korisnik unese "EOF" karakter.
// Program treba prvo da ispise sve unesene brojeve,
// te nakon toga da ispise samo one brojeve koji zadovoljavaju
// sljedeci uslov:  v[n-1] > v[n] < v[n+1]
//

#include <iostream>
#include <vector>
using std::cout, std::cin, std::endl;

int main() {
	double input;
	std::vector<double> v;
	cout << "Unesi broj: ";
	while (cin >> input) {
		cout << "Unesi broj: ";
		v.push_back(input);
	}
	cout << "Unijeli ste brojeve: " << endl;
	for (const auto& i : v) cout << i << "\t";
	cout << "\nBrojevi koji su manji"
		 << "od svog prethodnika i sljedbenika su:\n";
	for (auto i = 1; i < v.size() - 1; i++) {
		if (v[i] < v[i - 1] && v[i] < v[i + 1])
			cout << v[i] << "\t";
	}
	cout << endl;
	return 0;
}