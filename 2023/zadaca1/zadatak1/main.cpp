#include <iostream>
#include <string>
#include <limits>
using std::cout, std::cin, std::endl, std::string;

#if _WIN32

#include <conio.h>

void clrscr(void) { system("cls"); }

#else

#include <unistd.h>

void clrscr(void) { system("clear"); }

#endif

namespace Temperature {
	const double celsiusKelvinCoeff = 273.15;
	const double celsiusFahrenCoeff = 1.8;
	const double fahrenheitCoeff = 32.;
	const double lowestFahrenheitVal = -459.67;
	void menu() {
		cout << "Please choose converter:\n"
			 << "1. Celsius to Fahrenheit\n"
			 << "2. Fahrenheit to Celsius\n"
			 << "3. Celsius to Kelvin\n"
			 << "4. Kelvin to Celsius\n"
			 << "5. Fahrenheit to Kelvin\n"
			 << "6. Kelvin to Fahrenheit\n"
			 << "0. Back\n"
			 << "Your choice: ";
	}
}

namespace Length {
	const double InchCmCoeff = 2.54;
	const double footMeterCoeff = 3.28;
	const long double lightYearKmCoeff = 9.461e+12;
	void menu() {
		cout << "Please choose converter:\n"
			 << "1. Light years to kilometers\n"
			 << "2. Kilometers to light years\n"
			 << "3. Feet to meters\n"
			 << "4. Meters to feet\n"
			 << "5. Inches to centimeters\n"
			 << "6. Centimeters to inches\n"
			 << "0. Back\n"
			 << "Your choice: ";
	}
}

namespace Speed {
	const double mileKilometerCoeff = 1.609;
	void menu() {
		cout << "Please choose converter:\n"
			 << "1. Kilometers per hour to miles per hour\n"
			 << "2. Miles per hour to kilometers per hour\n"
			 << "0. Back\n"
			 << "Your choice: ";
	}
}

namespace Weight {
	const double lbsKilogrammeCoeff = 2.205;
	void menu() {
		cout << "Please choose converter:\n"
			 << "1. Pounds to kilogrammes\n"
			 << "2. Kilogramems to pounds\n"
			 << "0. Back\n"
			 << "Your choice: ";
	}
}

namespace Fuel_Economy {
	const double lhkmMpgCoeff = 235.215;
	void menu() {
		cout << "Please choose converter:\n"
			 << "1. Liters per hundred kilometers to miles per gallon\n"
			 << "2. Miles per gallon to liters per hundred kiloemeters\n"
			 << "0. Back\n"
			 << "Your choice: ";
	}
}

void menu() {
	cout << "Please enter one of the following options:\n"
		 << "1. Temperature\n"
		 << "2. Speed\n"
		 << "3. Length\n"
		 << "4. Weight\n"
		 << "5. Fuel economy\n"
		 << "0. Exit\n"
		 << "Your choice: ";
}

void fixCin() {
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool checkIfValid(long double input, double parameter) {
	if (input < parameter || cin.fail()) {
		clrscr();
		cout << "Invalid input." << endl;
		fixCin();
		return false;
	}
	return true;
}

long double inputCase(string str1, string str2) {
	long double input;
	cout << "Enter " << str1 << " in " << str2 << ": ";
	cin >> input;
	return input;
}

void printCase(
	string str1,
	string str2,
	string str3,
	double multiplicator,
	double addBefore,
	double addAfter,
	double parameter) {
	clrscr();
	long double input = inputCase(str1, str2);
	if (checkIfValid(input, parameter)) {
		clrscr();
		cout << input << " " << str2 << " is "
			 << (input + addBefore)* multiplicator + addAfter
			 << " " << str3 << "." << endl;
	}
}


int main() {
	cout << "Welcome to Unit converter. ";
	menu();
	int con;
	cin >> con;
	while (
		con == 1 ||
		con == 2 ||
		con == 3 ||
		con == 4 ||
		con == 5
	) {
		switch (con) {
			case 1: {
					using namespace Temperature;
					Temperature::menu();
					int choice;
					cin >> choice;
					if (cin.fail()) fixCin();
					switch (choice) {
						case 1:
							printCase(
								"temperature",
								"degrees Celsius",
								"degrees Fahrenheit",
								celsiusFahrenCoeff,
								0.,
								fahrenheitCoeff,
								-celsiusKelvinCoeff
							);
							break;
						case 2:
							printCase(
								"temperature",
								"degrees Fahrenheit",
								"degrees Celsius",
								1. / celsiusFahrenCoeff,
								-fahrenheitCoeff,
								0.,
								lowestFahrenheitVal
							);
							break;
						case 3:
							printCase(
								"temperature",
								"degrees Celsius",
								"degrees Kelvin",
								1.,
								0.,
								celsiusKelvinCoeff,
								-celsiusKelvinCoeff
							);
							break;
						case 4:
							printCase(
								"temperature",
								"degrees Kelvin",
								"degrees Celsius",
								1.,
								0.,
								-celsiusKelvinCoeff,
								0.
							);
							break;
						case 5:
							printCase(
								"temperature",
								"degrees Fahrenheit",
								"degrees Kelvin",
								1. / celsiusFahrenCoeff,
								-fahrenheitCoeff,
								celsiusKelvinCoeff,
								lowestFahrenheitVal
							);
							break;
						case 6:
							printCase(
								"temperature",
								"degrees Kelvin",
								"degrees Fahrenheit",
								celsiusFahrenCoeff,
								-celsiusKelvinCoeff,
								32.,
								0.
							);
							break;
					}
					break;
				}
			case 2: {
					using namespace Speed;
					Speed::menu();
					int choice;
					cin >> choice;
					if (cin.fail()) fixCin();
					switch (choice) {
						case 1:
							printCase(
								"speed",
								"kilometers per hour",
								"miles per hour",
								1. / mileKilometerCoeff,
								0.,
								0.,
								0.
							);
							break;
						case 2:
							printCase(
								"speed",
								"miles per hour",
								"kilometers per hour",
								mileKilometerCoeff,
								0.,
								0.,
								0.
							);
							break;
					}
					break;
				}
			case 3: {
					using namespace Length;
					Length::menu();
					int choice;
					cin >> choice;
					if (cin.fail()) fixCin();
					switch (choice) {
						case 1:
							printCase(
								"length",
								"light years",
								"kilometers",
								lightYearKmCoeff,
								0.,
								0.,
								0.
							);
							break;
						case 2:
							printCase(
								"length",
								"kilometers",
								"light years",
								1. / lightYearKmCoeff,
								0.,
								0.,
								0.
							);
							break;
						case 3:
							printCase(
								"length",
								"feet",
								"meters",
								1. / footMeterCoeff,
								0.,
								0.,
								0.
							);
							break;
						case 4:
							printCase(
								"length",
								"meters",
								"feet",
								footMeterCoeff,
								0.,
								0.,
								0.
							);
							break;
						case 5:
							printCase(
								"length",
								"inches",
								"centimeters",
								InchCmCoeff,
								0.,
								0.,
								0.
							);
							break;
						case 6:
							printCase(
								"length",
								"centimeters",
								"inches",
								1. / InchCmCoeff,
								0.,
								0.,
								0.
							);
							break;
					}
					break;
				}
			case 4: {
					using namespace Weight;
					Weight::menu();
					int choice;
					cin >> choice;
					if (cin.fail()) fixCin();
					switch (choice) {
						case 1:
							printCase(
								"weight",
								"pounds",
								"kilogrammes",
								1. / lbsKilogrammeCoeff,
								0.,
								0.,
								0.
							);
							break;
						case 2:
							printCase(
								"weight",
								"kilogrammes",
								"pounds",
								lbsKilogrammeCoeff,
								0.,
								0.,
								0.
							);
							break;
					}
					break;
				}
			case 5: {
					using namespace Fuel_Economy;
					Fuel_Economy::menu();
					int choice;
					cin >> choice;
					if (cin.fail()) fixCin();
					switch (choice) {
						case 1:
							printCase(
								"fuel economy",
								"liters per hundred kilometers",
								"miles per gallon",
								1000 / lhkmMpgCoeff,
								0.,
								0.,
								0.
							);
							break;
						case 2:
							printCase(
								"fuel economy",
								"miles per gallon",
								"liters per hundred kilometers",
								lhkmMpgCoeff / 1000,
								0.,
								0.,
								0.
							);
							break;
					}
					break;
				}
		}
		menu();
		cin >> con;
	}
	return 0;
}