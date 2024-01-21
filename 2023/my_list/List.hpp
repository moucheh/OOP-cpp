#pragma once
#include <initializer_list>
#include <stdexcept>
#include <iostream>
#include <string>

struct Node {
	int data{};
	Node* next{nullptr};
	Node* prev{nullptr};
};

class List {
private:
	unsigned long __size{};
	Node* head{nullptr};
	Node* tail{nullptr};
public:
	List() = default;
	List(const std::initializer_list<int>&);
	List(const List&);
	List(List&&);
	~List();

	void clear();

	List& operator=(const List&);
	List& operator=(List&&);

	Node* begin() const;
	Node* end() const;

	Node* rbegin() const;
	Node* rend() const;

	void push_back(const int& element);
	void push_front(const int& element);
	void insert(const int& element, const int& position);

	void pop_back();
	void pop_front();

	int& back();
	int& front();
	const int& back() const;
	const int& front() const;

	unsigned long size() const;
	bool empty() const;
};

void print_list(const List&);
void print_list_reverse(const List&);