#pragma once
#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>
class MojNizInt {
private:
	unsigned long velicina{};
	unsigned long kapacitet{1};
	int* alokator{nullptr};
public:
	MojNizInt();
	MojNizInt(const std::initializer_list<int>& lista);
	MojNizInt(const MojNizInt& drugi);
	MojNizInt(MojNizInt&& drugi);
	~MojNizInt();

	MojNizInt& operator=(const MojNizInt& drugi);
	MojNizInt& operator=(MojNizInt&& drugi);
	MojNizInt operator*(const int& multiplikator) const;
	MojNizInt operator+(const MojNizInt& drugi) const;
	MojNizInt operator++(int) const;
	MojNizInt& operator++();

	void push_back(const int& element);
	void pop_back();

	int& operator[](const int& indeks);
	const int& operator[](const int& indeks) const;

	int& front();
	const int& front() const;
	int& back();
	const int& back() const;

	int& at(const int& indeks);
	const int& at(const int& indeks) const;

	unsigned long size() const;
	unsigned long capacity() const;
};

void ispisiNiz(std::ostream& izlaz, const MojNizInt& niz);
std::ostream& operator<<(std::ostream& izlaz, const MojNizInt& niz);