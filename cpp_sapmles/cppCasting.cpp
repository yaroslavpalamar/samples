#include <iostream>
using namespace std;

/*
	1. without word virtual will be compilation error in line with dynamic_cast
	2. type casting for recover infomation loss:
		void advance_monsters(std::list<Monster*>& monsters);
		void dragon(std::list<Monster*>& monsters) {
    			advance_monsters(monsters);
    			for (Monster* m : monsters) {
        			Dragon *d = static_cast<Dragon*>(m); // or use dynamic_cast
			}
		}
		In current case with type casting you don't need to copy 
			all list data for creation list with static_cast<Dragon*>
	3. casting used to increase or decrease precision
	4. Type punning
	5. When reading data from network or disk it will generally be accessible 
		as a byte array or similar. 
		Using reinterpret_cast you can change it into a class or struct.
*/

int constPass(int* ptr)
{
	return (*ptr+7);
}

// for dynamic casting
class E { virtual  void fun() {} }; 
class F: public E { };

void dynamicCastSample()
{
	cout << "dynamic casting sample: " << endl;

	E *e1 = new E;
	F *f1 = dynamic_cast<F*>(e1);
	if(f1 != NULL) 
		cout<<"works"<<endl; 
	else
		cout<<"cannot cast E(parent) to F(child)" << endl; 
	
	F *f2 = new F;
	E *e2 = dynamic_cast<E*>(f2);
	
	if(e2 != NULL) 
		cout<<"works, converted from F(child) to E(parent)"<<endl; 
	else
		cout<<"cannot cast E(parent) to F" << endl;

	F *f3 = dynamic_cast<F*>(e2);
	
	if(f3 != NULL) 
		cout<<"E converted to F because e2 was F !!!in the begining!!!"<<endl; 
	else
		cout<<"E not converted to F" << endl;

}

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
	
	dynamicCastSample();
	return 0;
}

