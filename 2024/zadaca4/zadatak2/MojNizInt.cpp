#include "MojNizInt.hpp"

MojNizInt::MojNizInt() : alokator{new int[kapacitet]} {};

MojNizInt::MojNizInt(const std::initializer_list<int>& lista) :
	velicina{lista.size()},
	kapacitet{velicina},
	alokator{new int[kapacitet]} {
	std::copy(
		lista.begin(),
		lista.end(),
		alokator
	);
}

MojNizInt::MojNizInt(const MojNizInt& drugi) :
	velicina{drugi.velicina},
	kapacitet{drugi.kapacitet},
	alokator{new int[kapacitet]} {
	std::copy(
		drugi.alokator,
		drugi.alokator + drugi.velicina,
		alokator
	);
}

MojNizInt::MojNizInt(MojNizInt&& drugi) :
	velicina{drugi.velicina},
	kapacitet{drugi.kapacitet},
	alokator{drugi.alokator} {
	drugi.alokator = nullptr;
	drugi.kapacitet = 0;
	drugi.velicina = 0;
}

MojNizInt::~MojNizInt() { delete[] alokator; }

MojNizInt& MojNizInt::operator=(const MojNizInt& drugi) {
	if (this != &drugi) {
		delete[] alokator;
		velicina = drugi.velicina;
		kapacitet = drugi.kapacitet;
		alokator = new int[kapacitet];
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
	kapacitet = drugi.kapacitet;
	alokator = drugi.alokator;
	drugi.alokator = nullptr;
	drugi.kapacitet = 0;
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

MojNizInt MojNizInt::operator++(int) const {
	MojNizInt temp = *this;
	for (auto i = 0; i < size(); ++i)
		++temp[i];
	return temp;
}

MojNizInt& MojNizInt::operator++() {
	for (auto i = 0; i < size(); ++i)
		++(*this)[i];
	return *this;
}

void MojNizInt::push_back(const int& element) {
	if (velicina <= kapacitet) {
		(*this)[velicina] = element;
		++velicina;
		return;
	}
	kapacitet *= 2;
	int* temp = new int[kapacitet];
	std::copy(
		alokator,
		alokator + velicina,
		temp
	);
	delete[] alokator;
	alokator = temp;
	alokator[velicina] = element;
	++velicina;
}

void MojNizInt::pop_back() {
	if (velicina == 0)
		throw std::out_of_range{"Niz je prazan."};
	--velicina;
}

int& MojNizInt::operator[](const int& indeks) {
	return alokator[indeks];
}

const int& MojNizInt::operator[](const int& indeks) const {
	return alokator[indeks];
}

int& MojNizInt::front() {
	if (velicina == 0)
		throw std::out_of_range{"Niz je prazan."};
	return alokator[0];
}

const int& MojNizInt::front() const  {
	if (velicina == 0)
		throw std::out_of_range{"Niz je prazan."};
	return alokator[0];
}

int& MojNizInt::back() {
	if (velicina == 0)
		throw std::out_of_range{"Niz je prazan."};
	return alokator[velicina - 1];
}

const int& MojNizInt::back() const {
	if (velicina == 0)
		throw std::out_of_range{"Niz je prazan."};
	return alokator[velicina - 1];
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

unsigned long MojNizInt::size() const {
	return velicina;
}

unsigned long MojNizInt::capacity() const {
	return kapacitet;
}

void ispisiNiz(std::ostream& izlaz, const MojNizInt& niz) {
	for (auto i = 0; i < niz.size(); ++i)
		izlaz << niz[i] << ' ';
}

std::ostream& operator<<(std::ostream& izlaz, const MojNizInt& niz) {
	ispisiNiz(izlaz, niz);
	return izlaz;
}