#pragma once
#include <initializer_list>
#include <stdexcept>
#include <iostream>
#include <string>

template<typename T>
class List {
public:
	struct Node {
		T data{};
		Node* next{nullptr};
		Node* prev{nullptr};
	};

	List() = default;
	List(const std::initializer_list<T>&);
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

	void push_back(const T& element);
	void push_front(const T& element);
	void insert(const T& element, const int& position);

	void pop_back();
	void pop_front();

	T& back();
	T& front();
	const T& back() const;
	const T& front() const;

	unsigned long size() const;
	bool empty() const;
private:
	unsigned long __size{};
	Node* head{nullptr};
	Node* tail{nullptr};
};

template<typename T>
void print_list(const List<T>& list) {
	for (auto it = list.begin(); it != list.end(); it = it->next)
		std::cout << it->data << ' ';
}

template<typename T>
void print_list_reverse(const List<T>& list) {
	for (auto it = list.rbegin(); it != list.rend(); it = it->prev)
		std::cout << it->data << ' ';
}

template<typename T>
unsigned long List<T>::size() const {
	return __size;
}

template<typename T>
bool List<T>::empty() const {
	return !size();
}

template<typename T>
List<T>::List(const std::initializer_list<T>& list) {
	for (const auto& el : list)
		push_back(el);
}

template<typename T>
List<T>::List(const List<T>& list) {
	if (!list.empty())
		for (auto it = list.begin(); it != list.end(); it = it->next)
			push_back(it->data);
	else
		List<T>();
}

template<typename T>
List<T>::List(List<T>&& list)
	: __size{list.__size}, head{list.head}, tail{list.tail} {
	list.__size = 0;
	list.head = nullptr;
	list.tail = nullptr;
}

template<typename T>
List<T>& List<T>::operator=(const List<T>& list) {
	if (this != &list) {
		if (!empty())
			clear();
		for (auto it = list.begin() ; it != list.end(); it = it->next)
			push_back(it->data);
	}
	return *this;
}

template<typename T>
List<T>& List<T>::operator=(List<T>&& list) {
	if (!empty())
		clear();
	__size = list.__size;
	head = list.head;
	tail = list.tail;
	list.head = nullptr;
	list.tail = nullptr;
	list.__size = 0;
	return *this;
}

template<typename T>
void List<T>::clear() {
	while (head != nullptr) {
		auto next = head->next;
		delete head;
		head = next;
	}
	head = nullptr;
	tail = nullptr;
	__size = 0;
}

template<typename T>
void List<T>::push_back(const T& element) {
	Node* new_node = new Node;
	new_node->data = element;
	if (tail == nullptr) {
		head = new_node;
		tail = new_node;
	} else {
		auto temp = tail;
		temp->next = new_node;
		new_node->prev = temp;
		tail = new_node;
	}
	++__size;
}

template<typename T>
void List<T>::push_front(const T& element) {
	Node* new_node = new Node;
	new_node->data = element;
	if (head == nullptr) {
		head = new_node;
		tail = new_node;
	} else {
		auto temp = head;
		temp->prev = new_node;
		new_node->next = temp;
		head = new_node;
	}
	++__size;
}

template<typename T>
void List<T>::insert(const T& element, const int& position) {
	if (position > size())
		throw std::out_of_range(
			std::string{"position("} +
			std::to_string(position) +
			std::string{") > this->size() which is "} +
			std::to_string(size())
		);
	if (position == size()) {
		push_back(element);
		return;
	}
	if (position == 0) {
		push_front(element);
		return;
	}
	Node* new_node = new Node;
	new_node->data = element;
	auto it = begin();
	for (auto i = 0; i < position - 1; i++)
		it = it->next;
	new_node->prev = it;
	new_node->next = it->next;
	it->next = new_node;
}

template<typename T>
void List<T>::pop_back() {
	--__size;
	if (tail->prev == nullptr) {
		delete tail;
		tail = nullptr;
		head = nullptr;
		return;
	}
	auto temp = tail;
	tail = tail->prev;
	tail->next = nullptr;
	delete temp;
}

template<typename T>
void List<T>::pop_front() {
	--__size;
	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}
	auto temp = head;
	head = head->next;
	head->prev = nullptr;
	delete temp;
}

template<typename T>
T& List<T>::back() {
	if (empty())
		throw std::out_of_range{"The list is empty."};
	return tail->data;
}

template<typename T>
T& List<T>::front() {
	if (empty())
		throw std::out_of_range{"The list is empty."};
	return head->data;
}

template<typename T>
const T& List<T>::back() const {
	if (empty())
		throw std::out_of_range{"The list is empty."};
	return tail->data;
}

template<typename T>
const T& List<T>::front() const {
	if (empty())
		throw std::out_of_range{"The list is empty."};
	return head->data;
}

template<typename T>
typename List<T>::Node* List<T>::begin() const {
	if (empty())
		throw std::out_of_range{"The list is empty."};
	return head;
}

template<typename T>
typename List<T>::Node* List<T>::end() const {
	if (empty())
		throw std::out_of_range{"The list is empty."};
	return tail->next;
}

template<typename T>
typename List<T>::Node* List<T>::rbegin() const {
	if (empty())
		throw std::out_of_range{"The list is empty."};
	return tail;
}

template<typename T>
typename List<T>::Node* List<T>::rend() const {
	if (empty())
		throw std::out_of_range{"The list is empty."};
	return head->prev;
}

template<typename T>
List<T>::~List() {
	while (head != nullptr) {
		auto next = head->next;
		delete head;
		head = next;
	}
}