#include <iostream>
using namespace std;

/*Current example display what is functor(functional object)
- What is the main attribute of functor?
- What the difference between functor and function? 
(the difference is that functor can save some state for example in variable cout in example below)
*/

class TestFunctor {
public:
	// the main attribute of functor is overloaded operator () like below:
	void operator()(){
		cout << "I am functor " << count << endl;
		count++;
	}
private:
	// we can save some state in defined functor variables
	int count = 0;
};

class TestFunctorAdd {
public:
	// the main attribute of functor is overloaded operator () like below:
	int operator()(int a, int b){
		cout << "Add functor" << endl;
		return a + b;
	}

};

int main() {
	TestFunctor functor;
	// example how to call functor and save state inside the functor in variable count.
	functor();
	functor();
	functor();
	
	TestFunctorAdd functAdd;
	const int A=2;
	const int B=2;
	cout << A << "+" << B << "=" << functAdd(A,B) << endl;
	
	return 0;
}



