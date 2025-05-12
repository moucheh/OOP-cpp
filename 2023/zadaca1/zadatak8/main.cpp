#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
using std::cout, std::cin, std::endl, std::string;

int main() {
	srand(time(NULL));
	std::vector<int> hits;
	int n, num_of_hits;
	cout << "Unesite unesite broj kuglica: ";
	cin >> n;
	cout << "Unesite broj kuglica za izvlacenje: ";
	cin >> num_of_hits;
	for (int i = 0; i < num_of_hits; i++) {
		hits.push_back(rand() % n);
	}
	std::vector<int> sorted = hits;
	std::sort(sorted.begin(), sorted.end());
	cout << "Izvuceno\t\tSortirano" << endl;
	cout << string(50, '-') << endl;
	for (int i = 0; i < num_of_hits; i++) {
		cout << hits[i] << "\t\t\t" << sorted[i] << endl;
	}
}