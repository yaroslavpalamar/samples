#include <iostream>
#include <stdlib.h>
using namespace std;

// function to check whether x is numeric 
bool isNumericChar(char x) 
{ 
    return (x >= '0' && x <= '9')? true: false; 
}

/*
FYI in ASCII '0'==48, so if we need parse numbers from str "425", the algorithm is next
The first calculation of value = 0*10 + (*str) – '0' == 0 + 52-48 == 4, second: 0 + 50-48 == 2...
*/
int
atoi2 (const char* src)
{
	int res = 0;
	if (!src) {
		return res;
	}

	int signVal = 1;
	if (*src == '-') {
		signVal = -1;
		src++;
	}

	while (*src) {
		// return what we get in case if found not numeric value
		if (!isNumericChar(*src))
			return signVal*res;
		res = res*10 + *src-'0';
		src++;
	}

	return  signVal*res;
}

int
main (int argc, char**argv)
{
	char test2[] = "-2354679abc";
	cout << "test output for atoi function from stdlib.h: "
		 << atoi(test2) << endl;
	cout <<"test output for implemetated atoi2 fuction: "
		<< atoi2(test2) << endl;
	return 0;
}

