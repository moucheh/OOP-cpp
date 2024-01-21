#include <iostream>
#include "PrintLists.hpp"

namespace V10 {
	namespace Details {

		struct Node {
			std::string value;
			Node* next;
			Node(const std::string& str, Node* ptr) : value{str}, next{ptr} {}
			~Node() {
				std::cout << "Destroying: \"" << value << "\" value!" << std::endl;
			}
		};
	}

	class StringList {
	public:
		StringList() = default;

		StringList(StringList&& other) : count_{other.count_}, start_{other.start_} {
			other.count_ = 0;
			other.start_ = nullptr;
		}

		StringList& operator=(StringList&& other) {
			auto current = start_;
			while (current != nullptr) {
				auto next = current->next;
				delete current;
				current = next;
			}
			start_ = nullptr;
			start_ = other.start_;
			count_ = other.count_;
			other.count_ = 0;
			other.start_ = nullptr;
			return *this;
		}

		StringList(const StringList& other)
			: count_{other.count_} {
			auto temp = other.start_;
			for (auto i = 0; i < other.count_; ++i) {
				auto newNode = new Details::Node(temp->value, nullptr);
				if (start_ == nullptr) {
					start_ = newNode;
				} else {
					auto current = start_;
					while (current->next != nullptr)
						current = current->next;
					current->next = newNode;
				}
				temp = temp->next;
			}
		}

		StringList& operator=(const StringList& other) {
			count_ = other.count_;
			auto temp = other.start_;
			auto current = start_;
			while (current != nullptr) {
				auto next = current->next;
				delete current;
				current = next;
			}
			start_ = nullptr;
			for (auto i = 0; i < other.count_; ++i) {
				auto newNode = new Details::Node(temp->value, nullptr);
				if (start_ == nullptr) {
					start_ = newNode;
				} else {
					auto current = start_;
					while (current->next != nullptr)
						current = current->next;
					current->next = newNode;
				}
				temp = temp->next;
			}
			return *this;
		}

		~StringList() {
			while (start_ != nullptr) {
				auto next = start_->next;
				delete start_;
				start_ = next;
			}
		}

		int size() const {
			return count_;
		}

		bool empty() const {
			return start_ == nullptr;
		}

		void pushFront(const std::string& s) {
			auto* newNode = new Details::Node{s, nullptr};
			++count_;
			if (start_ == nullptr) {
				start_ = newNode;
				return;
			}
			newNode->next = start_;
			start_ = newNode;
		}

		void pushBack(const std::string& s) {
			auto* newNode = new Details::Node{s, nullptr};
			++count_;
			if (start_ == nullptr) {
				start_ = newNode;
				return;
			}
			auto* walk = start_;
			while (walk->next != nullptr) {
				walk = walk->next;
			}
			walk->next = newNode;
		}

		void popFront() {
			if (start_ == nullptr) return;
			--count_;
			auto* next = start_->next;
			delete start_;
			start_ = next;
		}

		void popBack() {
			if (start_ == nullptr) return;
			--count_;
			if (start_->next == nullptr) {
				delete start_;
				start_ = nullptr;
				return;
			}
			auto* walk = start_;
			auto* stalk = start_;
			while (walk->next != nullptr) {
				stalk = walk;
				walk = walk->next;
			}
			stalk->next = nullptr;
			delete walk;
		}

		void print() const {
			auto* walk = start_;
			while (walk != nullptr) {
				std::cout << walk->value << '\n';
				walk = walk->next;
			}
		}

	private:
		Details::Node* start_ = nullptr;
		int count_ = 0;
	};

}

int main (int argc, char* argv[]) {
	// Part1
	std::cout << "===============" << std::endl;
	std::cout << "List copy" << std::endl;
	V10::StringList lista1;
	lista1.pushBack("A");
	lista1.pushBack("B");
	V10::StringList lista2(lista1);
	lista2.pushBack("C");
	printLists(lista1, lista2);
	// // Part2
	std::cout << "List copy assignment" << std::endl;
	V10::StringList lista3;
	lista3 = lista2;
	lista1.popBack();
	printLists(lista1, lista2, lista3);
	// // Part 3
	std::cout << "List move" << std::endl;
	V10::StringList lista4(std::move(lista2));
	printLists(lista4, lista2);
	// // Part4
	std::cout << "List move assignment" << std::endl;
	lista1 = std::move(lista2);
	printLists(lista1, lista2);
	return 0;
}


