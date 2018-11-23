#include <iostream>
using namespace std;


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
	testCall(std::move(notReusableAfterMove));
	// reusable is destroid here and arr is nullptr
	return 0;
}

