#include <iostream>
using namespace std;

int constPass(int* ptr)
{
	return (*ptr+7);
}

// for dynamic casting
class E { virtual void fun() {} }; 
class F: public E { }; 

int main (int argc, char** argv)
{
	cout << "static casting sample: " << endl;
	// static casting (during compilation)
	float f = 4.5;
	int a = (int)f; // this C style casting
	int b= static_cast<int>(f);
	// second example of static casting 
	int i = 10; 
	void* v = static_cast<void*>(&i); 
	int* ip = static_cast<int*>(v);
	cout << b << "  " <<  *ip <<endl;

	cout << "const casting sample: " << endl;
	//pass const pointer with const_cast
	const int val = 10;
	const int *ptr = &val;
	int *ptr1 = const_cast <int *>(ptr);
	cout << constPass(ptr1) << endl;

	cout << "reinterpret casting sample: " << endl;
	int* p = new int(65); 
	char* ch = reinterpret_cast<char*>(p); 
	cout << *p << endl; 
	cout << *ch << endl; 
	cout << p << endl; 
	cout << ch << endl; 

	cout << "dynamic casting sample: " << endl;

	E *ee1 = new E;
	F *ff1 = dynamic_cast<F*>(ee1);
	if(ff1 != NULL) 
		cout<<"works"<<endl; 
	else
		cout<<"cannot cast E(parent) to F (E was as E obj)" << endl; 
	
	E *ee2 = new F;
	F *ff2 = dynamic_cast<F*>(ee2);
	
	if(ff2 != NULL) 
		cout<<"works, converted from E(parent) to F (E was as F obj) (up to down)"<<endl; 
	else
		cout<<"cannot cast E(parent) to F" << endl; 
	
	return 0;
}

