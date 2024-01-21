#include <iostream>
#include <string>
#include <vector>

//evo ga bubble sort algoritam

namespace my {
	template<typename random_it, typename lambda>
	void sort(random_it p, random_it k, lambda f ) {
		for (; p != k; ++p) {
			for (auto it = p + 1; it != k; ++it) {
				if (f(*it, *p)) {
					auto temp = *it;
					*it = *p;
					*p = temp;
				}
			}
		}
	}

	template<typename random_it>
	void sort(random_it p , random_it k) {
		sort(p, k, [](auto a, auto b) { return a < b; });
	}
}

int main() {
	std::vector<std::string> v{
		"hello",
		"Muhamed",
		"Taletovic",
		"Osman",
		"Aszpilicuetta",
		"Kladanj",
		"Sasa Matic - Oko moje"
	};
	my::sort(v.begin(), v.end(), [](std::string a, std::string b) {
		return a.size() < b.size();
	});
	for (const auto& i : v) {
		std::cout << i.size() << " : " << i << '\n';
	}
	std::cout << std::endl;
	return 0;
}