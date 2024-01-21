#include <iostream>
using std::cout, std::cin, std::endl;

int main() {
	int a, b;
	char operation;
	cin >> a;
	cin >> operation;
	cin >> b;
	switch (operation) {
		case '+':
			cout << a + b << endl;
			break;
		case '-':
			cout << a - b << endl;
			break;
		case '*':
			cout << a* b << endl;
			break;
		case '/':
			if (b == 0)
				cout << "Dijeljenje s nulom je nedefinirana operacija." << endl;
			else
				cout << (double)a / b << endl;
			break;
		case '%':
			cout << a % b << endl;
			break;
		case '^': {
				double result = 1;
				for (int i = 0; i < b; i++) {
					result *= a;
				}
				cout << result << endl;
				break;
			}
	}
	return 0;
}