#include <string>

template <typename T>
T foo(T a, T b);

int main() {
	foo(3, 4);
	foo("abc", "def");
	foo(std::string("a"), std::string("b"));
	foo(2, 4.f);
	/*
		^^^
		kompajler ne moze zakljuciti koji je tip T
		jer u funckiju prosljedjujemo int i float
		te je poziv dvosmislen
	*/
	foo<int>(2, 4.f);
	/*
		^^^
		ovo je u redu, jer eksplicitno navodimo
		koji je tip parametar T
		float se moze implicitno konvertovati u int
	*/
	foo<int>(3, std::string("a"));
	/*
		^^^
		string se ne moze implicitno konvertovati
		u int, stoga ovo je compile time error
	*/
	return 0;
}
