#pragma once
#include <iostream>
#include <algorithm>
#include <stdexcept>

class String {
private:
	unsigned long __size{};
	char* __ptr{nullptr};
public:
	String() = default;
	String(const char[]);
	String(const String&);
	String(String&&);
	~String();

	String& operator=(const String&);
	String& operator=(String&&);

	String operator+(const String&) const;
	String operator+(const char[]) const;
	String operator+(const char&) const;

	String& operator+=(const String&);
	String& operator+=(const char[]);
	String& operator+=(const char&);

	void clear();

	char* data();
	const char* data() const;

	void push_back(const char& element);
	void pop_back();

	char& front();
	char& back();

	char& operator[](const int& index);
	char& at(const int& index);
	const char& at(const int& index) const;

	void set_size(const unsigned long&);
	void allocate(char* ptr);

	unsigned long size() const;
	unsigned long length() const;
	bool empty() const;
};

String operator+(const char[], const String&);
String operator+(const char&, const String&);

std::ostream& operator<<(std::ostream&, const String&);
std::istream& operator>>(std::istream&, String&);

void print_String(std::ostream&, const String&);
void input_String(std::istream&, String&);