#include <iostream>
using namespace std;

/* 1. Example of double free or corruption !!!!!without!!!!! copy constructor:

In output you will get next result:
Error:
Constr addr 0x7fff98973980
passByVal
~Constr addr 0x7fff98973990
~Constr addr 0x7fff98973970
double free or corruption (fasttop): 0x0000000001bbfc20 ***
*/

class CopyConstrProblem {
    public:
    CopyConstrProblem(int size) {
        // allocate memory in constructor
        this->dynamData = new int(size);
        for (int i; i < size; i++) {
            dynamData[i]=i;
        }
        cout << "Constr addr " << this << endl ;
    }
    ~CopyConstrProblem() {
        cout << "~Constr addr " << this << endl ;
        delete[] dynamData;
    }
    
    
    /* 2. To fix the core dump you need to define your own copy constructor
        Result:
        Finished in 0 ms
        Constr addr 0x7ffc497b4450
        Copy Constr addr 0x7ffc497b4440
        Copy Constr addr 0x7ffc497b4460
        passByVal
        ~Constr addr 0x7ffc497b4460
        ~Constr addr 0x7ffc497b4440
        ~Constr addr 0x7ffc497b4450
    */
    /* Uncomment to fix the double free
    CopyConstrProblem (const CopyConstrProblem &other) {
        cout << "Copy Constr addr " << this << endl ;
        
        this->size = other.size;
        
        this->dynamData = new int(other.size);
        for (int i; i < other.size; i++) {
            this->dynamData[i]=other.dynamData[i];
        }
    }
    */
    
    
    private:
        int size;
        int *dynamData;
};


// passing by value (copy obj with copy constr)
void passByVal (CopyConstrProblem copyCo) {
    cout << "passByVal" << endl ;
}

int main() {
    const int SIZE = 5;
    CopyConstrProblem a(SIZE);
    
    // call default copy constructor
    CopyConstrProblem b(a);
    
    // call copy constructor from function
    passByVal(a); 
}
