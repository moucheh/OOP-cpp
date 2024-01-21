#include <iostream>
#include <bitset>

#if _WIN32

#include <conio.h>

void clrscr(void) { system("cls"); }

#else

#include <unistd.h>

void clrscr(void) { system("clear"); }

#endif

using std::cout, std::cin, std::endl;

void mainMenu() {
	cout << "Select register\n"
		 << "1. Register A\n"
		 << "2. Register B\n"
		 << "3. Swap values\n"
		 << "4. Exit\n"
		 << "Enter option: ";
}

void operationMenu(char selected) {
	clrscr();
	cout << "1. Print register " << selected << "\n"
		 << "2. Set bit in register " << selected << "\n"
		 << "3. Reset bit in register " << selected << "\n"
		 << "4. Back\n"
		 << "Enter option: ";
}
//   210
//5  101

int main() {
	mainMenu();
	int option;
	cin >> option;
	std::bitset<16> regA(0);
	std::bitset<16> regB(0);
	while (
		option == 1 ||
		option == 2 ||
		option == 3
	) {
		if (option == 1) {
			int choice;
			operationMenu('A');
			cin >> choice;
			if (choice == 1) {
				cout << regA << endl;
			} else if (choice == 2) {
				unsigned short bit_num;
				cout << "Enter bit number: ";
				cin >> bit_num;
				regA[bit_num] = 1;
				cout << "New register A value: "
					 << regA.to_ulong()
					 << endl << regA << endl;
			} else if (choice == 3) {
				unsigned short bit_num;
				cout << "Enter bit number: ";
				cin >> bit_num;
				regA[bit_num] = 0;
				cout << "New register A value: "
					 << regA.to_ulong()
					 << endl << regA << endl;
			} else if (choice == 4) {
				break;
			}
		} else if (option == 2) {
			int choice;
			operationMenu('B');
			cin >> choice;
			if (choice == 1) {
				cout << regB << endl;
			} else if (choice == 2) {
				unsigned short bit_num;
				cout << "Enter bit number: ";
				cin >> bit_num;
				regB[bit_num] = 1;
				cout << "New register B value: "
					 << regB.to_ulong()
					 << endl << regB << endl;
			} else if (choice == 3) {
				unsigned short bit_num;
				cout << "Enter bit number: ";
				cin >> bit_num;
				regB[bit_num] = 0;
				cout << "New register B value: "
					 << regB.to_ulong()
					 << endl << regB << endl;
			} else if (choice == 4) {
				break;
			}
		} else if (option == 3) {
			std::bitset<16> temp = regA;
			regA = regB;
			regB = temp;
		} else if (option == 4) {
			break;
		}
		cout << endl;
		mainMenu();
		cin >> option;
	}
	return 0;
}