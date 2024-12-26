#include <cassert>
#include <iostream>
#include <string>

using namespace std;

// basic linked list node
struct Node {
	int value;
	Node* next = nullptr;

	Node(int v);
};

// node constructor
Node::Node(int val = NULL) {
	value = val;
}

// inserts a new node at the end of the list
void insert(Node* node, int value) {

	Node* temp = new Node(value);
	Node* traverser = node;

	while (traverser->next != NULL) {
		traverser = traverser->next;
	}

	traverser->next = temp;
}

// print out each node in the list
void print_list(Node* node) {
	Node* traverser = node;
	while (traverser != NULL) {
		cout << traverser->value << endl;
		traverser = traverser->next;
	}
}

// attaches the final node back to the header making an infinite loop
void loop(Node* head) {
	cout << "Creating a loop by linking the end to the start." << endl;
	Node* traverser = head;
	while (traverser->next != NULL) {
		traverser = traverser->next;
	}
	traverser->next = head;
}


//detects whether or not there is a loop using a fast header and a slow header
bool detect_loop(Node* head) {
	Node* fast = head;
	Node* slow = head;

	cout << "Detecting if there is a loop . . ." << endl;

		while (fast->next != NULL) {
			fast = fast->next;
			if (fast == slow) {
				cout << "LOOP! at " << fast->value;
				return true;
			}
			slow = slow->next;
			if (fast->next != NULL) {
				fast = fast->next;
				if (fast == slow) {
					cout << "LOOP! at " << fast->value;
					return true;
				}
			}
		}
	cout << "No loop here!" << endl;
	return false;
}

void createLoop(Node* node_ptr, int length) {
	cout << "Creating linked list of length: " << length << endl;
	for (int i = 2; i <= length; i++) {
		insert(node_ptr, i);
	}
}


int main() {
	Node header(1);
	Node* header_ptr = &header;

	createLoop(header_ptr, 25);

	print_list(header_ptr);
	assert(!detect_loop(header_ptr));

	loop(header_ptr);
	assert(detect_loop(header_ptr));

	return 0;
}