#include <iostream>

int a = 10;

namespace ns1 {
	int a = 20;
	namespace ns2 {
		int a = 30;
	}
}

int main (int argc, char* argv[]) {
	using std::cout, std::endl;
	// Ispisati vrijednost svih varijabli imenovanih "a"
	int a = 40;
	cout << ::a << endl; // globalna varijabla a
	cout << ns1::a << endl; // globalna varijabla a iz namespace-a ns1
	cout << ns1::ns2::a << endl; // globalna varijabla a iz namesapce-a ns2 koji se nalazi u namespaceu ns1
	cout << a << endl; // lokalna varijabla unutar opsega
	return 0;
}
