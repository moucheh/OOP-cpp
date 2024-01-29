#pragma once
#include <initializer_list>
#include <algorithm>
#include <stdexcept>
#include <iostream>

template<typename T>
class Matrica {
private:
	int brojRedova{};
	int brojKolona{};
	T* alokator{nullptr};
public:
	Matrica<T>();
	Matrica<T>(const std::initializer_list<T>& _list);
	Matrica<T>(const int& br_red, const int& br_kol);
	Matrica<T>(const Matrica<T>& druga);
	~Matrica<T>();

	Matrica<T>& operator=(const Matrica<T>& druga);
	Matrica<T>& operator=(Matrica<T>&& druga);

	Matrica<T> operator+(const Matrica<T> druga) const;
	Matrica<T> operator-(const Matrica<T> druga) const;

	Matrica<T> operator*(const T& skalar) const;
	Matrica<T> operator/(const T& skalar) const;

	Matrica<T>& operator+=(const Matrica<T>& druga);
	Matrica<T>& operator-=(const Matrica<T>& druga);

	Matrica<T>& operator*=(const T& skalar);
	Matrica<T>& operator/=(const T& skalar);

	T& operator()(const int& i, const int& j) {
		return alokator[i * brojKolona + j];
	}

	const T& operator()(const int& i, const int& j) const {
		return alokator[i * brojKolona + j];
	}

	int getBrojRedova() const { return brojRedova; }
	int getBrojKolona() const { return brojKolona; }
	int size() const { return brojRedova * brojKolona; }
};

template<typename T>
Matrica<T>::Matrica() {}

template<typename T>
Matrica<T>::Matrica(const std::initializer_list<T>& lista) {
	auto it = lista.begin();
	brojRedova = *it;
	++it;
	brojKolona = *it;
	++it;
	if (lista.size() - 2 > brojRedova * brojKolona)
		throw std::domain_error{
		"Naveli vise elemenata nego sto je potrebno."
	};
	alokator = new T[brojRedova * brojKolona];
	std::copy(
		it,
		lista.end(),
		alokator
	);
}

template<typename T>
Matrica<T>::Matrica(const Matrica<T>& druga) :
	brojRedova{druga.brojRedova},
	brojKolona{druga.brojKolona},
	alokator{new T[brojRedova * brojKolona]} {
	std::copy(
		druga.alokator,
		druga.alokator + druga.brojRedova * druga.brojKolona,
		alokator
	);
}

template<typename T>
Matrica<T>::Matrica(const int& br_red, const int& br_kol) :
	brojRedova{br_red},
	brojKolona{br_kol},
	alokator{new T[brojRedova * brojKolona]}
{}

template<typename T>
Matrica<T>::~Matrica<T>() { delete[] alokator; }

template<typename T>
Matrica<T>& Matrica<T>::operator=(const Matrica<T>& druga) {
	if (this != &druga) {
		delete[] alokator;
		brojRedova = druga.brojRedova;
		brojKolona = druga.brojKolona;
		alokator = new T[brojRedova * brojKolona];
		std::copy(
			druga.alokator,
			druga.alokator + druga.brojRedova * druga.brojKolona,
			alokator
		);
	}
	return *this;
}

template<typename T>
Matrica<T>& Matrica<T>::operator=(Matrica<T>&& druga) {
	brojRedova = druga.brojRedova;
	brojKolona = druga.brojKolona;
	alokator = druga.alokator;
	druga.alokator = nullptr;
	druga.brojKolona = 0;
	druga.brojRedova = 0;
	return *this;
}

template<typename T>
Matrica<T>& Matrica<T>::operator+=(const Matrica<T>& druga) {
	if (brojRedova != druga.brojRedova || brojKolona != druga.brojKolona)
		throw std::domain_error{"Dimenzije matrica nisu iste."};
	for (auto i = 0; i < brojRedova * brojKolona; ++i)
		alokator[i] += druga.alokator[i];
	for (auto i = 0; i < brojRedova; ++i) {
		for (auto j = 0; j < brojKolona; ++j) {
			(*this)(i, j) += druga(i, j);
		}
	}
	return *this;
}

template<typename T>
Matrica<T>& Matrica<T>::operator-=(const Matrica<T>& druga) {
	if (brojRedova != druga.brojRedova || brojKolona != druga.brojKolona)
		throw std::domain_error{"Dimenzije matrica nisu iste."};
	for (auto i = 0; i < brojRedova * brojKolona; ++i)
		alokator[i] -= druga.alokator[i];
	return *this;
}

template<typename T>
Matrica<T> Matrica<T>::operator+(const Matrica<T> druga) const {
	if (brojRedova != druga.brojRedova || brojKolona != druga.brojKolona)
		throw std::domain_error{"Dimenzije matrica nisu iste."};
	auto temp = *this;
	for (auto i = 0; i < brojRedova * brojKolona; ++i)
		temp.alokator[i] += druga.alokator[i];
	return temp;
}

template<typename T>
Matrica<T> Matrica<T>::operator-(const Matrica<T> druga) const {
	if (brojRedova != druga.brojRedova || brojKolona != druga.brojKolona)
		throw std::domain_error{"Dimenzije matrica nisu iste."};
	auto temp = *this;
	for (auto i = 0; i < brojRedova * brojKolona; ++i)
		temp.alokator[i] -= druga.alokator[i];
	return temp;
}

template<typename T>
Matrica<T>& Matrica<T>::operator*=(const T& skalar) {
	for (auto i = 0; i < brojRedova * brojKolona; ++i)
		alokator[i] *= skalar;
	return *this;
}

template<typename T>
Matrica<T>& Matrica<T>::operator/=(const T& skalar) {
	for (auto i = 0; i < brojRedova * brojKolona; ++i)
		alokator[i] *= skalar;
	return *this;
}

template<typename T>
Matrica<T> Matrica<T>::operator*(const T& skalar) const {
	auto temp = *this;
	for (auto i = 0; i < brojRedova * brojKolona; ++i)
		temp.alokator[i] *= skalar;
	return temp;
}

template<typename T>
Matrica<T> Matrica<T>::operator/(const T& skalar) const {
	if (skalar == 0)
		throw std::domain_error{"Dijeljenje s nulom nije definisano."};
	auto temp = *this;
	for (auto i = 0; i < brojRedova * brojKolona; ++i)
		temp.alokator[i] /= skalar;
	return temp;
}

template<typename T>
std::ostream& operator<<(std::ostream& izlaz, const Matrica<T>& matr) {
	for (auto i = 0; i < matr.getBrojRedova(); ++i) {
		for (auto j = 0; j < matr.getBrojKolona(); ++j) {
			izlaz << matr(i, j) << '\t';
		}
		izlaz << '\n';
	}
	return izlaz;
}