#include <iostream>
using namespace std;

/*forward_list sample similar to STL implementation with methods:
push_back()
getSize()
operator []
*/

template <typename T>
class List {
    public:
        List();
        ~List();
    
        void push_back(T data);
        int getSize(){return size;}
    
        T& operator[] (const int index);
        void pop_front();
        void clear();
    
        void push_front(T data);
        void insert(int index, T val);
        void removeAt(int index);
        void pop_back();
    
    private:
        template <typename B>
        class Node {
            public:
                Node* pNext;
                B data;
            
                Node(B data = B(), Node *pNext = nullptr) {
                    this->data = data;
                    this->pNext = pNext;
                }
        };
    
        int size;
        Node <T> *head;
};

template <typename T>
List<T>::List() {
    size = 0;
    head = nullptr;
}

template <typename T>
List<T>::~List() {   
    clear();
}

template <typename T>
void List<T>::push_back(T data){
    if (head == nullptr) {
        head = new Node<T>(data);
    } else {
        Node<T> *current = this->head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node <T>(data);
    }
    size++;
}


template <typename T>
T& List<T>::operator[] (const int index) {
    int counter = 0;
    Node<T> *current = this->head;
    while (current != nullptr) {
        //cout << current->data << endl;
        if (counter == index) {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

template <typename T>
void List<T>::pop_front() {
    Node<T> *tmp = this->head;
    head = tmp->pNext;
    delete tmp;
    size--;
}


template<typename T>
void List<T>::clear() {
    while (size) {
        pop_front();
    }
}

template<typename T>
void List<T>::push_front(T data) {
    // point your attantion to second parameter head
    head = new Node<T>(data, head);
    size++;
}

template<typename T>
void List<T>::insert(int index, T val) {
    Node<T> * previous = this->head;
    
    if (index == 0) {
        push_front(val);
    } else {
        for (int i = 0; i< index; i++) {
            previous = head->pNext;
        }
    }
    Node<T> *newNode = new Node<T>(val, previous->pNext);
    previous->pNext=newNode;
    size++;
}

template<typename T>
void List<T>::removeAt(int index) {
    Node<T> * previous = this->head;
    
    if (index == 0) {
        pop_front();
    } else {
        for (int i = 0; i< index; i++) {
            previous = head->pNext;
        }
    }
    Node<T> *nodeToDelete = previous->pNext;
    previous->pNext = nodeToDelete->pNext;
    delete nodeToDelete;
    size--;
}


template<typename T>
void List<T>::pop_back(){
    removeAt(size-1);
}

int main() {
    List<int> lst;
    lst.push_back(1);
    lst.push_back(10);
    lst.push_back(15);
    
    // check method getSize()
    cout << "size of linked list is " << lst.getSize() << endl;
    
    // check how work operator [] 
    cout << "by index 2 you data = " << lst[2] << endl;
    
    // remove first node from linked list
    lst.pop_front();
    
    // check the size of linked list after removing
    cout << "size of linked list after pop_front " << lst.getSize() << endl  << endl;
    
    lst.clear();
    cout << "size of linked list after method clear() " << lst.getSize() << endl << endl;
    
    // push_back randomly 10 numbers inside list (from 0 to 10)
    int numberCount = 10 ;
    //cin >> numberCount;
    for (int i ; i < numberCount; i++) {
        lst.push_back(rand()%10);
    }
    
    // display all data from linked list:
    cout << "print all data in linked list: " << endl << endl;
    for (int i; i < lst.getSize(); i++) {
        cout << lst[i] << endl;
    }
    
    // push_front() method test
    lst.push_front(11);
    lst.push_front(12);
    cout << "display fist two nodes: first: " << lst[0] << " second: " << lst[1] <<  endl << endl;
    
    // insert method check
    cout << "insert two values by index 3 and 2 with values 3000 and 4444" << endl;
    lst.insert(3, 3000);
    lst.insert(2, 4444);
    cout << "display two nodes by index: index 3: " << lst[3] << " index 2: " << lst[2] <<  endl << endl;
    
    // removeAt() function test
    cout << "call removeAt(2) fuction" << endl;
    lst.removeAt(2);
    cout << "compare with previous result node 2, check whether node was changed after removeAT(): " << lst[2]  <<  endl << endl;
    
    // check pop_back method 
    cout << "size of linked list before pop_back " << lst.getSize() << endl;
    cout << "print current last element: " << lst[lst.getSize()-1]  <<  endl;
    lst.pop_back();
    cout << "size of linked list after pop_back " << lst.getSize() << endl;
    cout << "print last element and compare with previous one: " << lst[lst.getSize()-1]  <<  endl;
}