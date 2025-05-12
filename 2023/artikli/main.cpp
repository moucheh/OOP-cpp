#include <iostream>
#include <fstream>
#include <unistd.h>
#include <limits>

using std::cout, std::cin, std::endl, std::string;

bool check_int(string str);
bool check_double(string str);
int input_int();
double input_double();

void input_items(int& n);
void output_items(int& n);
void delete_file();

void mainMenu(int& con, int& n) {
	cout << "Glavni meni\n"
		 << "Izaberite jednu od ponudjenih opcija:\n"
		 << "1. Unos racuna\n"
		 << "2. Stampanje racuna\n"
		 << "3. Brisanje fajla\n"
		 << "4. Izlaz iz programa\n"
		 << "Biram: ";
	con = input_int();
	switch (con) {
		case 1:
			input_items(n);
			mainMenu(con, n);
		case 2:
			output_items(n);
			mainMenu(con, n);
		case 3:
			delete_file();
			mainMenu(con, n);
		case 4:
			exit(0);
	}
}

void input_items(int& n) {
	system("clear");
	std::ofstream input("artikli.txt");
	cout << "Unesi broj artikala: ";
	n = input_int();
	input << n << endl;
	cout << endl;
	for (int i = 0; i < n; i++) {
		string name;
		cout << "Unesite naziv artikla: ";
		getline(cin, name);
		cout << "Unesite kolicinu artikala: ";
		auto quantity = input_int();
		cout << "Unesite cijenu artikla: ";
		auto price = input_double();
		cout << "\n";
		name[0] = toupper(name[0]);
		input << name << endl
			  << quantity << endl
			  << price << endl
			  << "}" << endl;
	}
	input.close();
	cout << endl;
}

void output_items(int& n) {
	system("clear");
	std::ifstream output("artikli.txt");
	if (output.is_open()) {
		output >> n;
		if (n == 0 || output.fail()) {
			cout << "Nema unesenih artikala\n\n";
			output.close();
			return;
		}
		auto total = 0.;
		output.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		string name;
		int quantity;
		double price;
		for (auto i = 0; i < n; i++) {
			getline(output, name);
			output >> quantity;
			output >> price;
			total += quantity * price;
			cout << "Artikal " << i + 1
				 << "\nNaziv artikla: " << name
				 << "\nKolicina artikala: " << quantity
				 << "\nCijena artikla: " << price << " KM"
				 << endl;
			output.ignore(1, '}');
			output.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << endl;
		}
		cout << "Ukupan iznos: " << total << " KM" << endl;
	} else
		cout << "Datoteka ne moze biti pronadjena!" << endl;
	output.close();
	cout << endl;
}

void delete_file() {
	system("clear");
	cout << "Sadrzaj fajla je obrisan\n\n";
	std::ofstream del("artikli.txt");
	del.close();
}

int main() {
	int con, n;
	mainMenu(con, n);
}

bool check_int(string str) {
	for (const auto& i : str) {
		if (isdigit(i) == false)
			return false;
	}
	return true;
}

bool check_double(string str) {
	auto dotcount = 0;
	auto invalid = false;
	for (const auto& i : str) {
		if (i != '.' && isdigit(i) == false)
			invalid = true;
		if (i == '.')
			dotcount++;
	}
	if (!invalid) {
		if (dotcount <= 1)
			return true;
	}
	return false;
}

int input_int() {
	string str;
	getline(cin, str);
	while (true) {
		if (check_int(str)) return stoi(str);
		else {
			cout << "Morate unijeti vrijednost int tipa!\nUnos: ";
			getline(cin, str);
		}
	}
}

double input_double() {
	string str;
	getline(cin, str);
	while (true) {
		if (check_double(str)) return std::stod(str);
		else {
			cout << "Morate unijeti vrijednost double tipa!\nUnos: ";
			getline(cin, str);
		}
	}
}
