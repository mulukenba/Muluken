#include <iostream>
using namespace std;

// Node class representing each element in circular singly linked list.
class Node {
	public:
		int data;
		Node *next;

		Node(int value): data(value), next(nullptr) {}
};

// CircularSinglyLinkedList class managing all operations on circular singly linked list.
class CircularSinglyLinkedList {
	private:
		Node *tail;

	public:
		CircularSinglyLinkedList(): tail(nullptr) {}

		void insertAtBeginning(int value) {
			Node *newNode = new Node(value);
			if (!tail) {
				tail = newNode;
				tail->next = tail;
			} else {
				newNode->next = tail->next;
				tail->next = newNode;
			}
		}

		void insertAtEnd(int value) {
			insertAtBeginning(value);
			tail = tail->next;
		}

		void insertAtPosition(int value, int position) {
			if (position == 0 || !tail) {
				insertAtBeginning(value);
				return;
			}
			Node *newNode = new Node(value);
			Node *current = tail->next;

			for (int i = 0; i < position - 1 && current != tail; i++)
				current = current->next;

			if (current == tail) {
				cout << "Position out of bounds." << endl;
				delete newNode;
				return;
			}

			newNode->next = current->next;
			current->next = newNode;

			if (current == tail)
				tail = newNode;
		}

		void deleteFromBeginning() {
			if (!tail) {
				cout << "List is empty." << endl;
				return;
			}
			Node *toDelete = tail->next;

			if (toDelete == tail) {
				tail = nullptr;
			} else {
				tail->next = toDelete->next;
			}
			delete toDelete;
		}

		void deleteFromEnd() {
			if (!tail) {
				cout << "List is empty." << endl;
				return;
			}
			if (tail == tail->next) {
				delete tail;
				tail = nullptr;
				return;
			}
			Node *current = tail->next;

			while (current->next != tail)
				current = current->next;

			current->next = tail->next;
			delete tail;
			tail = current;
		}

		void deleteFromPosition(int position) {
			if (!tail || position < 0) {
				cout << "Invalid operation." << endl;
				return;
			}
			if (position == 0) {
				deleteFromBeginning();
				return;
			}

			Node *current = tail->next;

			for (int i = 0; i < position && current != tail; i++)
				current = current->next;

			if (current == tail) {
				cout << "Position out of bounds." << endl;
			}

			else {
				Node *toDelete = current;

				current = current -> next;

				current -> next = current -> next;
			}

			delete toDelete;
		}

		void display() const {
			if (!tail) {
				cout << "List is empty." << endl;
			}

			else {
				Node *current = tail -> next;

				do {
					cout << current -> data << " -> ";
					current = current -> next;
				} while (current != tail -> next);

				cout << "(back to start)" << endl;
			}
		}

		~CircularSinglyLinkedList() {
			while (tail)
				deleteFromBeginning();
		}
};

int main() {
	CircularSinglyLinkedList list ;
	int choice, value, position ;

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
				cin >> value ;
				list.insertAtBeginning(value);
				break ;

			case 2:
				cout << "Enter value: ";
				cin >> value ;
				list.insertAtEnd(value);
				break ;

			case 3:
				cout << "Enter value and position: ";
				cin >> value >> position ;
				list.insertAtPosition(value, position);
				break ;

			case 4:
				list.deleteFromBeginning();
				break ;

			case 5:
				list.deleteFromEnd();
				break ;

			case 6:
				cout << "Enter position: ";
				cin >> position ;
				list.deleteFromPosition(position);
				break ;

			case 7:
				list.display();
				break ;

			case 8:
				cout << "Exiting..." << endl ;
				break ;

			default:
				cout << "Invalid choice! Please try again." << endl ;
		}
	} while (choice != 8);

	return 0 ;
}

