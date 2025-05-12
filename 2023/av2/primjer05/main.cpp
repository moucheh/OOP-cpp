#include <iostream>

int a = 9;
double c;

int main () {
	using std::cout, std::endl;
	short d = 4;
	{
		int a = 5;
		cout << "a = " << a << endl;
	}
	cout << "a = " << a << endl
		 << "d = " << d << endl
		 << "c = " << c << endl;
	{
		char a = 'V';
		float c = 4.f;
		cout << "a = " << a << endl
			 << "c = " << c << endl;
	}
	return 0;
}
