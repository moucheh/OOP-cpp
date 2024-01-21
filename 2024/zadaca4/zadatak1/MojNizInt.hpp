#pragma once
#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>

class MojNizInt {
private:
	unsigned long velicina{};
	int* alokator{nullptr};
public:
	MojNizInt();
	MojNizInt(const std::initializer_list<int>& lista);

	MojNizInt(const MojNizInt& drugi);

	MojNizInt(MojNizInt&& drugi);
	~MojNizInt() { delete[]  alokator;	}

	MojNizInt& operator=(const MojNizInt& drugi);

	MojNizInt& operator=(MojNizInt&& drugi);

	MojNizInt operator*(const int& multiplikator) const;
	MojNizInt operator+(const MojNizInt& drugi) const;

	MojNizInt operator++(int);

	MojNizInt& operator++();

	void push_back(const int& element);

	int& operator[](const int& indeks) {
		return alokator[indeks];
	}

	const int& operator[](const int& indeks) const {
		return alokator[indeks];
	}

	int& at(const int& indeks);

	const int& at(const int& indeks) const;

	unsigned long size() const {
		return velicina;
	}
};

void ispisiNiz(std::ostream& izlaz, const MojNizInt& niz);
std::ostream& operator<<(std::ostream& izlaz, const MojNizInt& niz);