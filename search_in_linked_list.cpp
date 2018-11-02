#include <iostream>
using namespace std;

/* Write the code for getting element from linked list with complexity O(n).
As input values you have:
1. pointer to head of linked list 
2. offset FROM LAST element in linked list to index of element what we NEED TO BE FOUND.

In result function getValFromEndOffset(int offsetFromEnd) should return data of element which the same as index of offsetFromEnd.
*/


class List {
        class Node {
            public:
                int data;    
                Node * pNext;
                    
                Node(int data = 0, Node *pNext = nullptr) {
                    this->data = data;
                    this->pNext = pNext;
                }
        };
	int size;
	Node* head;
	void clear();
public:
	List();
	~List();
	int getSize(){return size;}
	void push_back(int data);
	int getValFromEndOffset(int offsetFromEnd);
	int& operator[] (const int index);
	void pop_front();
};

List::List() {
    head = nullptr; 
    size = 0;
}

List::~List() {
    clear();
}

void
List::push_back(int data) {
    if (head == nullptr) {
        head = new List::Node(data);
    } else {
        List::Node * current = this->head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new List::Node(data);
    }
    size++;
}

int&
List::operator[] (const int index) {
    int counter = 0;
    Node *current = this->head;
    while (current != nullptr) {

        if (counter == index) {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
	cout << "out of bounds" << endl;
}

void 
List::pop_front() {
    Node *tmp = this->head;
    head = tmp->pNext;
    delete tmp;
    size--;
}

void 
List::clear() {
    while (size) {
        pop_front();
    }
}

int 
List::getValFromEndOffset (int offsetFromEnd) {
    const int offsetFromBegin {getSize() - offsetFromEnd - 1}; //-1 because of nullptr
    const List::Node* lst {head};
    int counter = 0;
 
    while (lst != nullptr) {
        if (counter++ == offsetFromBegin)
            return lst->data;
        lst = lst->pNext;
    }
	cout << "need to handle error." << endl;
	return -1;
}

int 
main() {
    List lst;
	
    // add three elements to list
    lst.push_back(1);
    lst.push_back(10);
    lst.push_back(15);
	
	// push_back randomly 20 numbers inside list (from 0 to 20)
    int numberCount = 20;
    //cin >> numberCount;
    for (int i ; i < numberCount; i++) {
        lst.push_back(rand() % 20);
    }
    
    // display all data from linked list:
    cout << "print all data in linked list: " << endl << endl;
    for (int i; i < lst.getSize(); i++) {
        cout << lst[i] << endl;
    }
	
	// print size of linked list
	cout << "size of linked list " << lst.getSize() << endl;
	
	int offsetFromEnd = 2;
	
	int byIndex = lst[lst.getSize() - offsetFromEnd -1]; // -1 because index of linked list head started from 0.
	int byFunc = lst.getValFromEndOffset (offsetFromEnd);
	
	if (byIndex == byFunc) {
		// print value using operator []:
		cout << "print value using operator []: " << byIndex << endl;
	
		// unit test for function getValFromEndOffset
		cout << "print return value from getValFromEndOffset: " << byFunc << endl;
	}
	
	return 0;
}
