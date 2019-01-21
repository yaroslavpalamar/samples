#include <iostream>
using namespace std;

/*
	1. move constructor with rvalue ref &&
	2. pass value by lval ref don't call cnstructor
	3. pass value by val call copy constructor
	4. use std::move and call move constructor, old moved objec can't be reusable and
		alloc data assigned to nullptr
*/

class TestArrMove {
	int size;
	int* arr;
public:
	TestArrMove (int size)
	{
		cout << "constructor" << endl;
		this->size=size;
		arr = new int[size];
		for (int i = 0; i< size; ++i) {
			arr[i] = 12345;
		}
	}
	TestArrMove (const TestArrMove& other)
	{
		size = other.size;
		arr = new int [size];
		for (int i = 0; i <size; ++i) {
			arr[i] = other.arr[i];
		}
		cout << "copy constructor" << endl;
	}

	TestArrMove (TestArrMove&& other)
        {
		size = other.size;
		arr = other.arr;
		other.arr = nullptr;
		cout << "move constructor" << endl;
        }

	~TestArrMove() 
	{
		cout << "destructor" << endl;
		delete [] arr;
	}
};

void testCall(TestArrMove tst)
{
}
void testCallByLvalRef(TestArrMove& tst)
{
}

int 
main (int argc, char** argv)
{
	TestArrMove notReusableAfterMove = TestArrMove(100);
	testCallByLvalRef(notReusableAfterMove); // don't call any constructor (notReusableAfterMove can be reusable)
	testCall(notReusableAfterMove);  // call copy constructor (can be reusable after copy constructor)
	testCall(std::move(notReusableAfterMove)); // not reusable after move, destroid here and arr is nullptr
	cout << "end" << endl;
	return 0;
}

