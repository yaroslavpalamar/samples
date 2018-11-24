#include <iostream>
#include <vector>
using namespace std;

struct BigStruct
{
	// let's imagine that current struct contain a lot of variables
	long long l;
	bool b;
	float f;
	BigStruct() = default;
	BigStruct(long long l, bool b, float f) : l(l), b(b), f(f) 
	{
		cout << "constructor for l,b,f"<< endl;
	}
	~BigStruct() 
	{
		cout << "destructor" << endl;
	}
};

struct PrivVec
{
	// variadic template
	template<typename ... Args>
	void addToPrivV(Args&& ... args)
	{
		v.emplace_back(forward<Args>(args)...);
	}
private:
	vector<BigStruct> v;
};

int 
main (int argc, char** argv)
{

	// 1 Example with emplace_back using:
	vector <BigStruct> v1;
	{
		BigStruct b1(1,1,3);
		v1.push_back(b1); 		// copy constr for b1
		v1.push_back(move(b1)); 	//move constructor callfor  b1
		v1.push_back(BigStruct(1,1,2)); //also move constructor for new object
		
		// THE QUESTION IS IT POSSIBLE STORE NEW OBJECT OF b1 WITHOUT MOVE CONSTRUCTOR
		// JUST CALL CONSTRUCTOR INSIDE THE VECTOR.
		v1.emplace_back(1,1,3); 	// perfect forwarding

	}

	// 2 Example with forward:
	PrivVec p2;
	BigStruct b2(2,0,2);
	//p2.addToPrivV(2,0,2); // let's imagine we using lvalue inside addToPriv() in that case
	// if we try the same syntax as in previous example for perfect forwarding then will get error
	// To fix such problem and use perfect forwarding we will use next sintax:
	p2.addToPrivV(2,0,2);	
	return 0;
}

