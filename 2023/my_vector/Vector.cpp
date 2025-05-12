#include "Vector.hpp"

//helper functions

void print_Vector(const Vector& __vector) {
	std::cout << '{';
	for (auto i = 0; i < __vector.size(); i++) {
		if (i == __vector.size() - 1)
			std::cout << __vector.at(i);
		else
			std::cout << __vector.at(i) << ", ";
	}
	std::cout << '}';
}

int* begin(const Vector& __vector) {
	return __vector.begin();
}

int* end(const Vector& __vector) {
	return __vector.end();
}

//constructors

Vector::Vector(const std::initializer_list<int>& __list)
	: __size{__list.size()}, __allocator{new int[__size]} {
	std::copy(
		__list.begin(),
		__list.end(),
		__allocator
	);
}

Vector::Vector(const int& __number, const int& __element) {
	__size = __number;
	__allocator = new int[__size];
	for (auto it = __allocator; it != __allocator + __size; ++it)
		*it = __element;
}

Vector::Vector(int* __begin, int* __end) {
	int __counter{};
	for (auto it = __begin; it != __end; ++it)
		++__counter;
	__size = __counter;
	delete[] __allocator;
	__allocator = new int[__size];
	std::copy(
		__begin,
		__end,
		__allocator
	);
}

Vector::Vector(const Vector& __other)
	: __size{__other.__size}, __allocator{new int[__size]} {
	std::copy(
		__other.__allocator,
		__other.__allocator + __other.__size,
		__allocator
	);
}

Vector::Vector(Vector&& __other)
	: __size{__other.__size}, __allocator{__other.__allocator} {
	__other.__size = 0;
	__other.__allocator = nullptr;
}

//methods

int* Vector::begin() const {
	return __allocator;
}

int* Vector::end() const {
	return __allocator + __size;
}

const int* Vector::cbegin() const {
	return __allocator;
}

const int* Vector::cend() const {
	return __allocator + __size;
}

unsigned long Vector::size() const {
	return __size;
}

void Vector::clear() {
	__size = 0;
	delete[] __allocator;
}

bool Vector::empty() const {
	return !__size;
}

Vector& Vector::operator=(const Vector& __other) {
	if (this != &__other) {
		delete[] __allocator;
		__size = __other.__size;
		__allocator = new int[__size];
		std::copy(
			__other.__allocator,
			__other.__allocator + __other.__size,
			__allocator
		);
	}
	return *this;
}

Vector& Vector::operator=(Vector&& __other) {
	delete[] __allocator;
	__size = __other.__size;
	__allocator = __other.__allocator;
	__other.__size = 0;
	__other.__allocator = nullptr;
	return *this;
}

void Vector::push_back(const int& __element) {
	++__size;
	int* temp = new int[__size];
	std::copy(
		__allocator,
		__allocator + __size - 1,
		temp
	);
	delete[] __allocator;
	__allocator = temp;
	back() = __element;
}

void Vector::pop_back() {
	if (__size == 0)
		throw std::out_of_range{"The vector is empty."};
	--__size;
	int* temp = new int[__size];
	std::copy(
		__allocator,
		__allocator + __size,
		temp
	);
	delete[] __allocator;
	__allocator = temp;
}

int& Vector::operator[](const int& __index) {
	return __allocator[__index];
}

int& Vector::at(const int& __index) {
	if (__size == 0)
		throw std::out_of_range{"The vector is empty."};
	if (__index >= __size)
		throw std::out_of_range{
		std::string{"Out of range, index "} +
		std::to_string(__index) +
		std::string{" is >= this->__size which is "} +
		std::to_string(__size)
	};
	return __allocator[__index];
}

const int& Vector::at(const int& __index) const {
	if (__size == 0)
		throw std::out_of_range{"The vector is empty."};
	if (__index >= __size)
		throw std::out_of_range{
		"Out of range, index " + std::to_string(__index) +
		" is >= this->__size which is " + std::to_string(__size)
	};
	return __allocator[__index];
}

int& Vector::back() {
	if (__size == 0)
		throw std::out_of_range{"The vector is empty."};
	return __allocator[__size - 1];
}
const int& Vector::back() const {
	if (__size == 0)
		throw std::out_of_range{"The vector is empty."};
	return __allocator[__size - 1];
}

int& Vector::front() {
	if (__size == 0)
		throw std::out_of_range{"The vector is empty."};
	return __allocator[0];
}
const int& Vector::front() const {
	if (__size == 0)
		throw std::out_of_range{"The vector is empty."};
	return __allocator[0];
}


void Vector::assign(const std::initializer_list<int>& __list) {
	__size = __list.size();
	delete[] __allocator;
	__allocator = new int[__size];
	std::copy(
		__list.begin(),
		__list.end(),
		__allocator
	);
}

void Vector::assign(const int& __number, const int& __element) {
	__size = __number;
	delete[] __allocator;
	__allocator = new int[__size];
	for (auto it = __allocator; it != __allocator + __size; ++it)
		*it = __element;
}

void Vector::assign(int* __begin, int* __end) {
	int __counter{};
	for (auto it = __begin; it != __end; ++it)
		++__counter;
	__size = __counter;
	delete[] __allocator;
	__allocator = new int[__size];
	std::copy(
		__begin,
		__end,
		__allocator
	);
}

Vector::~Vector() {
	delete[] __allocator;
}