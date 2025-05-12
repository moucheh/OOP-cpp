#include "List.hpp"

void print_list(const List& list) {
	for (auto it = list.begin(); it != list.end(); it = it->next)
		std::cout << it->data << ' ';
}

void print_list_reverse(const List& list) {
	for (auto it = list.rbegin(); it != list.rend(); it = it->prev)
		std::cout << it->data << ' ';
}

unsigned long List::size() const {
	return __size;
}

bool List::empty() const {
	return !size();
}

List::List(const std::initializer_list<int>& list) {
	for (const auto& el : list)
		push_back(el);
}

List::List(const List& list) {
	if (!list.empty())
		for (auto it = list.begin(); it != list.end(); it = it->next)
			push_back(it->data);
	else
		List();
}

List::List(List&& list)
	: __size{list.__size}, head{list.head}, tail{list.tail} {
	list.__size = 0;
	list.head = nullptr;
	list.tail = nullptr;
}

List& List::operator=(const List& list) {
	if (this != &list) {
		if (!empty())
			clear();
		for (auto it = list.begin() ; it != list.end(); it = it->next)
			push_back(it->data);
	}
	return *this;
}

List& List::operator=(List&& list) {
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

void List::clear() {
	while (head != nullptr) {
		auto next = head->next;
		delete head;
		head = next;
	}
	head = nullptr;
	tail = nullptr;
	__size = 0;
}

void List::push_back(const int& element) {
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

void List::push_front(const int& element) {
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

void List::insert(const int& element, const int& position) {
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

void List::pop_back() {
	auto temp = tail;
	tail = tail->prev;
	tail->next = nullptr;
	delete temp;
	--__size;
}

void List::pop_front() {
	auto temp = head;
	head = head->next;
	head->prev = nullptr;
	delete temp;
	--__size;
}

int& List::back() {
	if (empty())
		throw std::out_of_range{"The list is empty."};
	return tail->data;
}

int& List::front() {
	if (empty())
		throw std::out_of_range{"The list is empty."};
	return head->data;
}

const int& List::back() const {
	if (empty())
		throw std::out_of_range{"The list is empty."};
	return tail->data;
}

const int& List::front() const {
	if (empty())
		throw std::out_of_range{"The list is empty."};
	return head->data;
}

Node* List::begin() const {
	if (empty())
		throw std::out_of_range{"The list is empty."};
	return head;
}

Node* List::end() const {
	if (empty())
		throw std::out_of_range{"The list is empty."};
	return tail->next;
}

Node* List::rbegin() const {
	if (empty())
		throw std::out_of_range{"The list is empty."};
	return tail;
}

Node* List::rend() const {
	if (empty())
		throw std::out_of_range{"The list is empty."};
	return head->prev;
}

List::~List() {
	while (head != nullptr) {
		auto next = head->next;
		delete head;
		head = next;
	}
}