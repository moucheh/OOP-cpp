#pragma once
#include <iostream>
#include <stdexcept>
#include <initializer_list>

template<typename T>
class Queue {
	struct Node {
		T _value{};
		Node* next{nullptr};
		Node(T value, Node* ptr) : _value{value}, next{ptr} {}
	};
public:
	Queue() = default;
	Queue(Queue<T>&& other) : _size{other._size}, _bottom{other._bottom} {
		other._bottom = nullptr;
		other._size = 0;
	}
	Queue(const Queue<T>& other);
	Queue<T>& operator=(const Queue<T>& other);
	Queue<T>& operator=(Queue<T>&& other);
	~Queue();

	Queue(const std::initializer_list<T>& list);

	Queue<T>& push(const T& el);
	void pop();

	T& top();
	const T& top() const;

	void print(std::ostream& output) const;

	bool empty() { return _bottom == nullptr; }
	unsigned long size() { return _size; }
private:
	unsigned long _size{};
	Node* _bottom{nullptr};
};

template<typename T>
Queue<T>& Queue<T>::push(const T& el) {
	auto newNode = new Node{el, nullptr};
	if (empty())
		_bottom = newNode;
	else {
		auto current = _bottom;
		while (current->next != nullptr)
			current = current->next;
		current->next = newNode;
	}
	++_size;
	return *this;
}

template<typename T>
void Queue<T>::pop() {
	if (empty())
		throw std::out_of_range{"The container is empty."};
	auto next = _bottom->next;
	delete _bottom;
	_bottom = next;
	--_size;
}

template<typename T>
Queue<T>::Queue(const Queue<T>& other) {
	auto current = other._bottom;
	while (current != nullptr) {
		push(current->_value);
		current = current->next;
	}
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
	while (!empty())
		pop();
	_bottom = nullptr;
	auto current = other._bottom;
	while (current != nullptr) {
		push(current->_value);
		current = current->next;
	}
	return *this;
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& other) {
	while (!empty())
		pop();
	_bottom = nullptr;
	_size = other._size;
	_bottom = other._bottom;
	other._size = 0;
	other._bottom = nullptr;
	return *this;
}


template<typename T>
Queue<T>::~Queue() {
	while (!empty()) {
		auto temp = _bottom->next;
		delete _bottom;
		_bottom = temp;
	}
}

template<typename T>
Queue <T>::Queue(const std::initializer_list<T>& list) {
	for (const auto& el : list)
		push(el);
}

template<typename T>
T& Queue<T>::top() {
	if (empty())
		throw std::out_of_range{"The container is empty."};
	return _bottom->_value;
}

template<typename T>
const T& Queue<T>::top() const {
	if (empty())
		throw std::out_of_range{"The container is empty."};
	return _bottom->_value;
}

template<typename T>
void Queue<T>::print(std::ostream& output) const {
	auto current = _bottom;
	while (current != nullptr) {
		output << current->_value << ' ';
		current = current->next;
	}
}

template<typename T>
std::ostream& operator<<(std::ostream& output, const Queue<T>& queue) {
	queue.print(output);
	return output;
}