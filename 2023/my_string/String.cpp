#include "String.hpp"

String operator+(const char array[], const String& second) {
	String first = array;
	return first + second;
}

String operator+(const char& ch, const String& other) {
	String temp;
	temp.set_size(other.size() + 1);
	temp.allocate(new char[temp.size()]);
	std::copy(
		other.data(),
		other.data() + other.size(),
		temp.data() + 1
	);
	temp[0] = ch;
	return temp;
}

std::ostream& operator<<(std::ostream& output, const String& str) {
	print_String(output, str);
	return output;
}

std::istream& operator>>(std::istream& input, String& str) {
	input_String(input, str);
	return input;
}

void print_String(std::ostream& output, const String& str) {
	for (auto i = 0; i < str.size(); ++i)
		output << str.at(i);
}

void input_String(std::istream& input, String& str) {
	if (!str.empty())
		str.clear();
	char buffer[100];
	input >> buffer;
	String result{buffer};
	str = result;
}

String::String(const char array[]) {
	auto it = array;
	int __counter{};
	while (*it++) ++__counter;
	__size = __counter;
	__ptr = new char[__size];
	for (auto i = 0; i < __size; i++)
		__ptr[i] = array[i];
}

String::String(const String& other)
	: __size{other.__size}, __ptr{new char[__size]} {
	std::copy(
		other.__ptr,
		other.__ptr + __size,
		__ptr
	);
}

String::String(String&& other)
	: __size{other.__size}, __ptr{other.__ptr} {
	other.__ptr = nullptr;
	other.__size = 0;
}

String::~String() {
	delete[] __ptr;
}

String& String::operator=(const String& other) {
	if (this != &other) {
		delete[] __ptr;
		__size = other.__size;
		__ptr = new char[__size];
		std::copy(
			other.__ptr,
			other.__ptr + other.__size,
			__ptr
		);
	}
	return *this;
}

String& String::operator=(String&& other) {
	__size = other.__size;
	__ptr = other.__ptr;
	other.__ptr = nullptr;
	other.__size = 0;
	return *this;
}

void String::clear() {
	__size = 0;
	delete[] __ptr;
}

String String::operator+(const String& other) const {
	String temp;
	temp.__size = __size + other.__size;
	temp.__ptr = new char[temp.__size];
	std::copy(
		__ptr,
		__ptr + __size,
		temp.__ptr
	);
	std::copy(
		other.__ptr,
		other.__ptr + other.__size,
		temp.__ptr + __size
	);
	return temp;
}

String String::operator+(const char array[]) const {
	String other = array;
	return *this + other;
}

String String::operator+(const char& ch) const {
	String temp;
	temp.__size = __size + 1;
	temp.__ptr = new char[temp.__size];
	std::copy(
		__ptr,
		__ptr + __size,
		temp.__ptr
	);
	temp.back() = ch;
	return temp;
}

String& String::operator+=(const String& second) {
	String first = *this;
	*this = first + second;
	return *this;
}

String& String::operator+=(const char array[]) {
	String first = *this;
	String second = array;
	*this = first + second;
	return *this;
}

String& String::operator+=(const char& ch) {
	String temp = *this;
	*this = temp + ch;
	return *this;
}

void String::push_back(const char& element) {
	++__size;
	auto temp = new char[__size];
	std::copy(
		__ptr,
		__ptr + __size,
		temp
	);
	delete[] __ptr;
	__ptr = temp;
	back() = element;
}

void String::pop_back() {
	if (empty())
		return;
	--__size;
	auto temp = new char[__size];
	std::copy(
		__ptr,
		__ptr + __size,
		temp
	);
	delete[] __ptr;
	__ptr = temp;
}

char& String::front() {
	if (empty())
		throw std::out_of_range{"The string is empty."};
	return __ptr[0];
}

char& String::back() {
	if (empty())
		throw std::out_of_range{"The string is empty."};
	return __ptr[__size - 1];
}

char& String::operator[](const int& index) {
	return __ptr[index];
}

char& String::at(const int& index) {
	if (index >= size())
		throw std::out_of_range{"Specified index is out of range."};
	return __ptr[index];
}

const char& String::at(const int& index) const {
	if (index >= size())
		throw std::out_of_range{"Specified index is out of range."};
	return __ptr[index];
}

void String::set_size(const unsigned long& new_size) {
	__size = new_size;
}

void String::allocate(char* ptr) {
	__ptr = ptr;
}

char* String::data() {
	return __ptr;
}

const char* String::data() const {
	return __ptr;
}


unsigned long String::size() const {
	return __size;
}

unsigned long String::length() const {
	return __size;
}

bool String::empty() const {
	return !size();
}