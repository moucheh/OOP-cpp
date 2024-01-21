#pragma once
#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <stdexcept>
#include <string>

class Vector {
private:
	unsigned long  __size{};
	int* __allocator = nullptr;
public:
	//constructors
	Vector() = default;
	Vector(const std::initializer_list<int>&);
	Vector(const int& __number, const int& __element = 0);
	Vector(int*, int*);
	Vector(const Vector&);
	Vector(Vector&&);

	~Vector();

	//operators
	Vector& operator=(const Vector&);
	Vector& operator=(Vector&&);
	int& operator[](const int& __index);

	void assign(const std::initializer_list<int>&);
	void assign(const int& __number, const int& __element = 0);
	void assign(int*, int*);

	void clear();
	bool empty() const;

	int* data() { return __allocator; }

	int& at(const int&);
	const int& at(const int&) const;

	int& back();
	const int& back() const;

	int& front();
	const int& front() const;

	void push_back(const int&);
	void pop_back();

	int* begin() const;
	int* end() const;
	const int* cbegin() const;
	const int* cend() const;

	unsigned long size() const;
};

void print_Vector(const Vector&);
int* begin(const Vector&);
int* end(const Vector&);