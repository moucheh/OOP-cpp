// Napisati funkciju copy_if koja uzima 4 parametra:
// 1. pocetak sekvence
// 2. kraj sekvence
// 3. destinacija
// 4. predicate funkcija
//
// copy_if treba da kopira elemente koji zadovoljavaju predicate funkciju
// ulazne sekvence na destinaciju. Funkcija treba da radi za razlicite tipove
// kontejnera.


#include <iostream>
#include <vector>
#include <list>

using std::cout, std::endl;

template<typename input_it, typename output_it, typename lambda>
void copy_if(
	input_it __begin,
	input_it __end,
	output_it dest,
	lambda predicate
) {
	for (; __begin != __end; ++__begin)
		if (predicate(*__begin))
			*dest = *__begin;
}

int main() {
	std::vector<int> vint{1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> parni;
	::copy_if(
		vint.begin(),
		vint.end(),
		std::back_inserter(parni),
	[](int n) {
		return !(n & 1);
	});
	cout << "Parni: " << endl;
	for (int n : parni) {
		cout << n << ' ';
	}
	cout << endl;
	std::list<int> lint{1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::list<int> neparni;
	::copy_if(
		lint.begin(),
		lint.end(),
		std::back_inserter(neparni),
	[](int n) {
		return n & 1;
	});
	cout << "Neparni: " << endl;
	for (int n : neparni) {
		cout << n << ' ';
	}
	cout << endl;
	std::list<std::string> lstr{
		"hello", "auto", "world", "ant", "all", "exercise"
	};
	std::list<std::string> stringovi_sa_a;
	::copy_if(
		lstr.rbegin(),
		lstr.rend(),
		std::back_inserter(stringovi_sa_a),
	[](std::string str) {
		return str.front() == 'a';
	});
	cout << "Stringovi koji pocinju"
		 << " sa a u obrnutom redoslijedu: " << endl;
	for (const auto& str : stringovi_sa_a) {
		cout << str << ' ';
	}
	cout << endl;
	return 0;
}
