#include <iostream>

using namespace std;

// basic linked list node
struct Node {
	int value;
	Node* next = nullptr;

	Node(int v);
};

// node constructor
Node::Node(int v = NULL) {
	value = v;
}

// inserts a new node at the end of the list
void insert(Node* node, int v) {
	
	Node* temp = new Node(v);
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
	Node* traverser = head;
	while (traverser->next != NULL) {
		traverser = traverser->next;
	}
	traverser->next = head;
}

//detects whether or not there is a loop using a fast header and a slow header
void detect_loop(Node* head) {
	Node* fast = head;
	Node* slow = head;
	while (fast->next != NULL) {
		cout << "Fast pointer value was: " << fast->value << endl;
		fast = fast->next;
		cout << "Fast pointer value is now: " << fast->value << endl;
		if (fast == slow) {
			cout << "LOOP! at " << fast->value;
			return;
		}
		cout << "Slow pointer value was: " << slow->value << endl;
		slow = slow->next;
		cout << "Slow pointer value is now: " << slow->value << endl;
		if (fast->next != NULL) {
			cout << "Fast pointer value was: " << fast->value << endl;
			fast = fast->next;
			cout << "Fast pointer value is now: " << fast->value << endl;
			if (fast == slow) {
				cout << "LOOP! at " << fast->value;
				return;
			}
		}
	}
	cout << "No loop here!" << endl;
	return;
}


int main() {
	Node header(1);
	Node* header_ptr = &header;

	for (int i = 2; i < 25; i++) {
		insert(header_ptr, i);
	}

	print_list(header_ptr);
	detect_loop(header_ptr);
	cout << "The linked list, now cycling the list by attaching the final element back to the front." << endl;
	loop(header_ptr);
	detect_loop(header_ptr);

	return 0;
}