#include <iostream>
#include <sstream>
using namespace std;

/*
 *
 * 00110
 * +
 * 00011
 * ——–
 * 01001
 *
 * To subtract 6-3, rewrite as 6+ (-3) need to make next steps:
 * 1. 00011 invert it will be 11100 - it is 1 compliment
 * 2. Add one to inverted number, result will be 11101 - second compliment
 *
 * 00110
 * +
 * 11101 (2s-complement of 3)
 * ——-
 * 00011
 * 	
 **/



//  Utility method to convert integer into string 
string toString(int n) 
{ 
	string str; 
	stringstream ss; 
	ss << n; 
	ss >> str; 
	return str; 
}
  
// Method to convert n to base negBase 
string toNegativeBase(int n, int negBase) 
{
	//  If n is zero then in any base it will be 0 only 
	if (n == 0) 
		return "0"; 
  
	string converted = ""; 
	while (n != 0) { 
		// Get remainder by negative base, it can be negative also 
		int remainder = n % negBase; 
		n /= negBase;
  
		// if remainder is negative, add abs(base) to it and add 1 to n 
		if (remainder < 0) { 
			remainder += (-negBase); 
			n += 1; 
		}
  
		// convert remainder to string add into the result 
		converted = toString(remainder) + converted; 
	}
	return converted; 
}
  
//  Driver code to test above methods 
int main() 
{ 
	int n; 
	cin >> n;
	int negBase = -10;
  
	cout << toNegativeBase(n, negBase); 
  
	return 0; 
}
