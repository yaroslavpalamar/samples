#include <iostream>
using namespace std;

/*Since remove_reference converts T& to T or T&& to T*/

template<typename T>
typename remove_reference<T>::type&& 
testMove(T&& a)
{
	return static_cast<typename remove_reference<T>::type&&>(a);
}

constexpr long int fib(int n) 
{ 
    return (n <= 1)? n : fib(n-1) + fib(n-2); 
} 
  

int 
main(){
	int a = 123;
	int b = 456;
	a = testMove(b);
	a = 777;
	cout << sizeof(a) << endl;
	cout << a << " and " << b<< endl;

	// value of res is computed at compile time.  
	const long int res = fib(30); 
	cout << res; 
	
	return 0;
}

