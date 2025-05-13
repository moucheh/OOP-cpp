#include "MojNizInt.hpp"

MojNizInt::MojNizInt() {};

MojNizInt::MojNizInt(const std::initializer_list<int>& lista)
	: velicina{lista.size()}, alokator{new int[velicina]} {
	std::copy(
		lista.begin(),
		lista.end(),
		alokator
	);
}

MojNizInt::MojNizInt(const MojNizInt& drugi)
	: velicina{drugi.velicina}, alokator{new int[velicina]} {
	std::copy(
		drugi.alokator,
		drugi.alokator + drugi.velicina,
		alokator
	);
}

MojNizInt::MojNizInt(MojNizInt&& drugi)
	: velicina{drugi.velicina}, alokator{drugi.alokator} {
	drugi.alokator = nullptr;
	drugi.velicina = 0;
}

MojNizInt& MojNizInt::operator=(const MojNizInt& drugi) {
	if (this != &drugi) {
		delete[] alokator;
		velicina = drugi.velicina;
		alokator = new int[velicina];
		std::copy(
			drugi.alokator,
			drugi.alokator + drugi.velicina,
			alokator
		);
	}
	return *this;
}

MojNizInt& MojNizInt::operator=(MojNizInt&& drugi) {
	delete[] alokator;
	velicina = drugi.velicina;
	alokator = drugi.alokator;
	drugi.alokator = nullptr;
	drugi.velicina = 0;
	return *this;
}

MojNizInt MojNizInt::operator*(const int& multiplikator) const {
	MojNizInt novi = *this;
	for (auto i = 0; i < novi.size(); ++i)
		novi[i] *= multiplikator;
	return novi;
}

MojNizInt MojNizInt::operator+(const MojNizInt& drugi) const {
	if (velicina != drugi.velicina)
		throw std::invalid_argument("Nizovi nisu iste duzine.");
	MojNizInt novi = *this;
	for (auto i = 0; i < novi.size(); ++i)
		novi[i] += drugi[i];
	return novi;
}

MojNizInt MojNizInt::operator++(int) {
	MojNizInt temp = *this;
	for (auto i = 0; i < size(); ++i)
		++(*this)[i];
	return temp;
}

MojNizInt& MojNizInt::operator++() {
	for (auto i = 0; i < size(); ++i)
		++(*this)[i];
	return *this;
}

void MojNizInt::push_back(const int& element) {
	int* temp = new int[size() + 1];
	std::copy(
		alokator,
		alokator + velicina,
		temp
	);
	delete[] alokator;
	alokator = temp;
	++velicina;
	alokator[size() - 1] = element;
}

int& MojNizInt::at(const int& indeks) {
	if (indeks < 0 )
		throw std::invalid_argument{"Van granica kontejnera."};
	if (indeks >= velicina)
		throw std::invalid_argument{"Van granica kontejnera."};
	return alokator[indeks];
}

const int& MojNizInt::at(const int& indeks) const {
	if (indeks < 0 )
		throw std::invalid_argument{"Van granica kontejnera."};
	if (indeks >= velicina)
		throw std::invalid_argument{"Van granica kontejnera."};
	return alokator[indeks];
}

void ispisiNiz(std::ostream& izlaz, const MojNizInt& niz) {
	for (auto i = 0; i < niz.size(); ++i)
		izlaz << niz[i] << ' ';
}

std::ostream& operator<<(std::ostream& izlaz, const MojNizInt& niz) {
	ispisiNiz(izlaz, niz);
	return izlaz;
}