#include <iostream>
#include <vector>

struct Node {
	int num;
	Node* next;
};

void printNodes(Node* start) {
	while (start != nullptr) {
		std::cout << start->num << std::endl;
		start = start->next;
	}
}

// Napisati funkciju createList koja treba da kreira 3 Node-a
// na heap-u i uveze ih koristeci pointer next. Za 'num'
// vrijednosti unutar svakog node-a staviti brojeve izmedju 10
// i 20.

Node* createList() {
	Node* node1 = new Node();
	Node* node2 = new Node();
	Node* node3 = new Node();
	node1->num = 4;
	node1->next = node2;
	node2->num = 2;
	node2->next = node3;
	node3->num = 0;
	node3->next = nullptr;
	return node1;
}

// Napisati funkciju removeList koja uzima pocetak uvezanih
// cvorova te ih uklanja sa heap-a.

void removeList(Node* start) {
	while (start != nullptr) {
		auto temp = start->next;
		delete start;
		start = temp;
	}
}

int main() {
	Node* List = createList();
	printNodes(List);
	removeList(List);
	return 0;
}
