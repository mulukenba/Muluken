#include <iostream>
using namespace std;

// Node class representing each element in circular doubly linked list.
class Node {
	public:
		int data;
		Node *next;
		Node *prev;

		Node(int value): data(value), next(nullptr), prev(nullptr) {}
};

// CircularDoublyLinkedList class managing all operations on circular doubly linked list.
class CircularDoublyLinkedList {
	private:
		Node *head;

	public:
		CircularDoublyLinkedList(): head(nullptr) {}

		void insertAtBeginning(int value) {
			Node *newNode = new Node(value);

			if (!head) {
				head = newNode ;
				head -> next = head ;
				head -> prev = head ;
			} else {
				newNode -> next = head ;
				newNode -> prev = head -> prev ;

				head -> prev -> next = newNode ;
				head -> prev = newNode ;

				head = newNode ;
			}
		}

		void insertAtEnd(int value) {
			insertAtBeginning(value);
			head = head -> next ;
		}

		void insertAtPosition(int value, int position) {
			if (position == 0) {
				insertAtBeginning(value);
				return;
			}

			Node *current = head ;
			for (int i = 0; i < position - 1 && current != head; i++) {
				current = current -> next ;
			}

			Node *newNode = new Node(value);
			newNode -> prev = current ;
			newNode -> next = current -> next ;

			current -> next = newNode ;

			if (newNode != head) {
				newNode -> next -> prev = current;
			} else {
				head = newNode;
			}
		}


		void deleteFromBeginning() {
			if (!head) {
				cout << "List is empty." << endl;
			}

			else {
				if (head == head) {
					delete head;
				} else {
					Node *toDelete = head ;
					head = head -> next ;

					head -> prev = toDelete -> prev ;
					toDelete -> prev -> next = head ;

					delete toDelete;
				}
			}
		}


		void deleteFromEnd() {
			if (!head) {
				cout << "List is empty." << endl;
			}

			else {
				if (head == head) {
					delete head;
				}

				else {
					Node *last = head -> prev ;

					last -> prev -> next = head ;
					head -> prev = last -> prev ;

					delete last ;
				}
			}
		}


		void deleteFromPosition(int position) {
			if (!head || position < 0) {
				cout << "Invalid operation." << endl;
			}

			else {
				if (position == 0) {
					deleteFromBeginning();
				}

				else {
					Node *current = head ;

					for (int i = 0; i < position && current != head; i++) {
						current = current -> next ;
					}

					if (current == head) {
						cout << "Position out of bounds." << endl;
					}

					else {
						current -> prev -> next = current -> next ;

						current -> next -> prev = current -> prev ;

						delete current ;
					}
				}
			}
		}


		void display() const {
			if (!head) {
				cout << "List is empty." << endl;
			}

			else {
				Node *current = head ;

				do {
					cout << current -> data << "<=>";
					current = current -> next ;
				} while (current != head);

				cout << "(back to start)" << endl;
			}
		}


		~CircularDoublyLinkedList() {
			while (head) {
				deleteFromBeginning();
			}
		}
};


int main() {
	CircularDoublyLinkedList list ;
	int choice, value, position ;

	do {
		cout << "\nMenu:\n";
		cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Delete from Beginning\n5. Delete from End\n6. Delete from Position\n7. Display List\n8. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice ;

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


