#pragma once
#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>

using size_t = unsigned long;

template<typename T>
class MojNiz {
private:
	size_t velicina{};
	size_t kapacitet{1};
	T* alokator{nullptr};
public:
	MojNiz<T>();
	MojNiz<T>(const MojNiz<T>& drugi);
	MojNiz<T>(MojNiz<T>&& drugi);
	MojNiz<T> operator=(const MojNiz<T>& drugi);
	MojNiz<T> operator=(MojNiz<T>&& drugi);
	~MojNiz<T>() { delete[] alokator; }

	template<typename U>
	MojNiz<T>(const MojNiz<U>& drugi);
	template<typename U>
	MojNiz<T> operator=(const MojNiz<U>& drugi);

	MojNiz<T>(const std::initializer_list<T>& _list);

	void push_back(const T& element);
	void pop_back();

	T& operator[](const int& indeks) {
		return alokator[indeks];
	}

	const T& operator[](const int& indeks) const {
		return alokator[indeks];
	}

	T& at(const int& indeks);
	const T& at(const int& indeks) const;

	T& back();
	const T& back() const;
	T& front();
	const T& front() const;

	T* data() { return alokator; }
	T* data() const { return alokator; }

	void clear() {
		velicina = 0;
		kapacitet = 0;
		alokator = nullptr;
	}

	MojNiz<T> operator+(const MojNiz<T>& drugi) const;

	template<typename U>
	auto operator+(const MojNiz<T>& drugi) const;

	MojNiz<T> operator*(const double& multiplikator) const;

	MojNiz<T>& operator++();
	MojNiz<T> operator++(int);

	size_t size() const {
		return velicina;
	}
	size_t capacity() const {
		return kapacitet;
	}
};

template<typename T>
MojNiz<T>::MojNiz() : alokator{new T[kapacitet]} {}

template<typename T>
MojNiz<T>::MojNiz(const MojNiz<T>& drugi) :
	velicina{drugi.velicina},
	kapacitet{drugi.kapacitet},
	alokator{new T[kapacitet]} {
	std::copy(
		drugi.data(),
		drugi.data() + drugi.size(),
		alokator
	);
}

template<typename T>
template<typename U>
MojNiz<T>::MojNiz(const MojNiz<U>& drugi) :
	velicina{drugi.size()},
	kapacitet{drugi.capacity()},
	alokator{new T[kapacitet]} {
	std::copy(
		drugi.data(),
		drugi.data() + drugi.size(),
		alokator
	);
}

template<typename T>
MojNiz<T>::MojNiz(MojNiz<T>&& drugi) :
	velicina{drugi.velicina},
	kapacitet{drugi.kapacitet},
	alokator{drugi.alokator} {
	drugi.clear();
}

template<typename T>
MojNiz<T> MojNiz<T>::operator=(const MojNiz<T>& drugi) {
	if (this != &drugi) {
		delete[] alokator;
		velicina = drugi.size();
		kapacitet = drugi.capacity();
		alokator = new T[kapacitet];
		std::copy(
			drugi.data(),
			drugi.data() + drugi.size(),
			alokator
		);
	}
	return *this;
}

template<typename T>
template<typename U>
MojNiz<T> MojNiz<T>::operator=(const MojNiz<U>& drugi) {
	if ((void*)this != (void*)&drugi) {
		delete[] alokator;
		velicina = drugi.size();
		kapacitet = drugi.capacity();
		alokator = new T[kapacitet];
		std::copy(
			drugi.data(),
			drugi.data() + drugi.size(),
			alokator
		);
	}
	return *this;
}

template<typename T>
MojNiz<T> MojNiz<T>::operator=(MojNiz<T>&& drugi) {
	delete[] alokator;
	velicina = drugi.size();
	kapacitet = drugi.capacity();
	alokator = drugi.data();
	drugi.clear();
	return *this;
}

template<typename T>
MojNiz<T>::MojNiz(const std::initializer_list<T>& _list) :
	velicina{_list.size()},
	kapacitet{_list.size()},
	alokator{new T[kapacitet]} {
	std::copy(
		_list.begin(),
		_list.end(),
		alokator
	);
}

template<typename T>
const T& MojNiz<T>::at(const int& indeks) const {
	if (indeks < 0)
		throw std::invalid_argument{"Van granica kontejnera."};
	if (indeks >= velicina)
		throw std::invalid_argument{"Van granica kontejnera."};
	return alokator[indeks];
}

template<typename T>
T& MojNiz<T>::at(const int& indeks) {
	if (indeks < 0)
		throw std::invalid_argument{"Van granica kontejnera."};
	if (indeks >= velicina)
		throw std::invalid_argument{"Van granica kontejnera."};
	return alokator[indeks];
}

template<typename T>
T& MojNiz<T>::back() {
	if (velicina == 0 )
		throw std::out_of_range{"Kontejner je prazan."};
	return alokator[velicina - 1];
}
template<typename T>
const T& MojNiz<T>::back() const {
	if (velicina == 0 )
		throw std::out_of_range{"Kontejner je prazan."};
	return alokator[velicina - 1];
}
template<typename T>
T& MojNiz<T>::front() {
	if (velicina == 0 )
		throw std::out_of_range{"Kontejner je prazan."};
	return alokator[0];
}
template<typename T>
const T& MojNiz<T>::front() const {
	if (velicina == 0 )
		throw std::out_of_range{"Kontejner je prazan."};
	return alokator[0];
}

template<typename T>
void MojNiz<T>::push_back(const T& element) {
	if (velicina < kapacitet) {
		(*this)[velicina] = element;
		++velicina;
		return;
	}
	kapacitet *= 2;
	T* temp = new int[kapacitet];
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

template<typename T>
void MojNiz<T>::pop_back() {
	if (velicina == 0)
		throw std::out_of_range{"Kontejner je prazan."};
	--velicina;
}

template<typename T>
MojNiz<T> MojNiz<T>::operator+(const MojNiz<T>& drugi) const {
	if (size() != drugi.size())
		throw std::domain_error{"Nisu iste duzine nizova"};
	auto temp = *this;
	for (auto i = 0; i < size(); ++i)
		temp[i] += drugi[i];
	return temp;
}

template<typename T>
template<typename U>
auto MojNiz<T>::operator+(const MojNiz<T>& drugi) const {
	if (size() != drugi.size())
		throw std::domain_error{"Nisu iste duzine nizova"};
	MojNiz < decltype(*(this)[0] + drugi[0]) > temp = *this;
	for (auto i = 0; i < size(); ++i)
		temp[i] += drugi[i];
	return temp;
}

template<typename T>
MojNiz<T> MojNiz<T>::operator*(const double& multiplikator) const {
	auto temp = *this;
	for (auto i = 0; i < size(); ++i)
		temp[i] *= multiplikator;
	return temp;
}


template<typename T>
MojNiz<T>& MojNiz<T>::operator++() {
	for (auto i = 0; i < velicina; ++i)
		++(*this)[i];
	return *this;
}

template<typename T>
MojNiz<T> MojNiz<T>::operator++(int) {
	auto temp = *this;
	for (auto i = 0; i < velicina; ++i)
		++(*this)[i];
	return temp;
}

template<typename T>
std::ostream& ispisiNiz(std::ostream& izlaz, const MojNiz<T>& niz) {
	for (auto i = 0; i < niz.size(); ++i)
		izlaz << niz[i] << ' ';
	return izlaz;
}

template<typename T>
std::ostream& operator<<(std::ostream& izlaz, const MojNiz<T>& niz) {
	ispisiNiz(izlaz, niz);
	return izlaz;
}