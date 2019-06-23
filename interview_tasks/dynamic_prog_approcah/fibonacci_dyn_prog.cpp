#include <iostream>

using namespace std;

int fib (int n)
{
	int f[n+2];
	f[0]=0;
	f[1]=1;
	
	for (int i = 2; i <= n; ++i ) {
		f[i] = f[i-1]+f[i-2];
	}

	return f[n];
}

int fibRec(int n)
{
	if (n == 0)
 		return 0;
	if (n == 1)
		return 1;
	return fib(n-1) + fib (n-2);
}

int fibNoArr(int n)
{
	int result = 0;
	if (n == 0)
		return 0;
	if (n == 1) 
		return 1;
	
	int buf0=0;
	int buf1=1;
	for (int i = 2; i <= n; ++i ) {
		result = buf0+buf1;
		buf0=buf1;
		buf1=result;
	}
	return result;
}

int 
main(int argc, char** argv)
{
	cout <<"fib(8) Dymaic programming solution with arr: "<< fib(8) << endl;
	cout <<"fib(8) Recurs solution: " << fibRec(8) << endl;
	cout <<"fib(8) Dynam solution without array: " << fibNoArr(8) << endl;
	return 0;
}

