#include <iostream>
using namespace std;

// Node class to represent each element in the list
class Node {
	public:
		int data; // Data part of the node
		Node *next; // Pointer to the next node

		// Constructor to initialize node with a value
		Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
	private:
		Node *head;
	public:
		SinglyLinkedList() : head(nullptr) {}

		// Function to insert a new node at the beginning of the list
		void insertAtBeginning(int value) {
			Node *newNode = new Node(value);
			newNode->next = head;
			head = newNode;
		}

		// Function to insert a new node at the end of the list
		void insertAtEnd(int value) {
			Node *newNode = new Node(value);
			if (!head) { //
				head = newNode;
				return;
			}
			Node *temp = head; // Temporary pointer to traverse the list
			while (temp->next) {
				temp = temp->next;
			}
			temp->next = newNode; // Link last node to the new node
		}

		// Function to insert a new node at a specific position
		void insertAtPosition(int value, int position) {
			if (position == 0) {
				insertAtBeginning(value);
				return;
			}
			Node *newNode = new Node(value);
			Node *temp = head;
			for (int i = 0; temp != nullptr && i < position - 1; i++) {
				temp = temp->next;
			}
			if (!temp) { // If position is out of bounds
				cout << "Position out of bounds." << endl;
				delete newNode;
				return;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}

		// Function to delete a node from the beginning of the list
		void deleteFromBeginning() {
			if (!head) { //
				cout << "List is empty." << endl;
				return;
			}
			Node *temp = head;
			head = head->next;
			delete temp;
		}

		// Function to delete a node from the end of the list
		void deleteFromEnd() {
			if (!head) {
				cout << "List is empty." << endl;
				return;
			}
			if (!head->next) {
				delete head;
				head = nullptr;
				return;
			}
			Node *temp = head;
			while (temp->next->next) {
				temp = temp->next;
			}
			delete temp->next;
			temp->next = nullptr; // Set next of second last node to nullptr
		}

		// Function to delete a node from a specific position
		void deleteFromPosition(int position) {
			if (!head) {
				cout << "List is empty." << endl;
				return;
			}
			if (position == 0) {
				deleteFromBeginning();
				return;
			}
			Node *temp = head; // Temporary pointer to traverse the list
			for (int i = 0; temp != nullptr && i < position - 1; i++) {
				temp = temp->next;
			}
			if (!temp || !temp->next) {
				cout << "Position out of bounds." << endl;
				return;
			}
			Node *toDelete = temp->next;
			temp->next = toDelete->next;
			delete toDelete;
		}

		// Function to display the linked list
		void display() {
			if (!head) {
				cout << "List is empty." << endl;
				return;
			}
			Node *temp = head;
			while (temp) {
				cout << temp->data << " -> ";
				temp = temp->next;
			}
			cout << "nullptr" << endl;
		}

		// Destructor to free allocated memory when object is destroyed
		~SinglyLinkedList() {
			while (head) {
				deleteFromBeginning();
			}
		}
};

// Main function for user interaction and menu-driven interface
int main() {
	SinglyLinkedList list;
	int choice, value, position;

	do {
		cout << "\nMenu:\n";
		cout << "1. Insert at Beginning\n";
		cout << "2. Insert at End\n";
		cout << "3. Insert at Position\n";
		cout << "4. Delete from Beginning\n";
		cout << "5. Delete from End\n";
		cout << "6. Delete from Position\n";
		cout << "7. Display List\n";
		cout << "8. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter value: ";
				cin >> value;
				list.insertAtBeginning(value);
				break;

			case 2:
				cout << "Enter value: ";
				cin >> value;
				list.insertAtEnd(value);
				break;

			case 3:
				cout << "Enter value and position: ";
				cin >> value >> position;
				list.insertAtPosition(value, position);
				break;

			case 4:
				list.deleteFromBeginning();
				break;

			case 5:
				list.deleteFromEnd();
				break;

			case 6:
				cout << "Enter position: ";
				cin >> position;
				list.deleteFromPosition(position);
				break;

			case 7:
				list.display();
				break;

			case 8:
				cout << "Exiting..." << endl;
				break;

			default:
				cout << "Invalid choice! Please try again." << endl;
		}
	} while (choice != 8);

	return 0;
}

