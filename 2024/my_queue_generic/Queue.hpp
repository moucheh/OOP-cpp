#pragma once
#include <stdexcept>

template<typename T>
class Queue {
	struct Node {
		T _value{};
		Node* next{nullptr};
		Node(T value, Node* ptr) : _value{value}, next{ptr} {}
	};
public:
	Queue() = default;
	Queue(Queue<T>&& drugi) : _size{drugi._size}, _top{drugi._top} {
		drugi._top = nullptr;
		drugi._size = 0;
	}
	~Queue();
	Queue<T>& push(const T& el);

	void pop();

	T& top();
	const T& top() const;

	bool empty() { return _top == nullptr; }
	unsigned long size() { return _size; }
private:
	Node* _top{nullptr};
	unsigned long _size{};
};

template<typename T>
Queue<T>& Queue<T>::push(const T& el) {
	auto newNode = new Node{el, nullptr};
	if (empty()) {
		_top = newNode;
	} else {
		auto current = _top;
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
	auto next = _top->next;
	delete _top;
	_top = next;
	--_size;
}

template<typename T>
Queue<T>::~Queue() {
	while (!empty()) {
		auto temp = _top->next;
		delete _top;
		_top = temp;
	}
}

template<typename T>
T& Queue<T>::top() {
	if (empty())
		throw std::out_of_range{"The container is empty."};
	return _top->_value;
}

template<typename T>
const T& Queue<T>::top() const {
	if (empty())
		throw std::out_of_range{"The container is empty."};
	return _top->_value;
}