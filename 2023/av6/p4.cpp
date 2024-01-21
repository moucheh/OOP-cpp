#include <iostream>
#include <functional>

int main() {
	int x = 7;
	std::function<void()> foo;
	{
		//pocetak zivotnog vijeka varijable z
		int z = 19;
		foo = [&]() {
			std::cout << x << " " << z << std::endl;
		};
		/*
			program uzrokuje nedefinisano ponasanje
			jer se poziva lambda izraz foo koji ispisuje
			vrijednost varijable z, koja ispari iz memorije
			prije poziva funckije

			vjerovatno ce vam i clang++ i g++
			izbaciti kao ispis 7 i 19
			nakon kompajliranja
			ali nije to bitno
			nemojte se sikirat nista
		*/
	}//kraj zivotnog vijeka varijable z
	foo();
	return 0;
}
