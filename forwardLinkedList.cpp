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
    cout << "size of linked list after pop_front " << lst.getSize() << endl;
    
    lst.clear();
    cout << "size of linked list after method clear() " << lst.getSize() << endl;
    
    // push_back randomly 10 numbers inside list (from 0 to 10)
    int numberCount = 10 ;
    //cin >> numberCount;
    for (int i ; i < numberCount; i++) {
        lst.push_back(rand()%10);
    }
    
    // display all data from linked list:
    cout << "print all data in linked list: " << endl;
    for (int i; i < lst.getSize(); i++) {
        cout << lst[i] << endl;
    }
}