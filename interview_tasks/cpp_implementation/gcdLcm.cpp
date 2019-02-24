#include <iostream>
using namespace std;

/*
	GCD (Greatest Common Divisor) or HCF (Highest Common Factor)
	example: GCD for 36,48 is 12.
	1. A simple solution is to find all prime factors of both numbers, but better 
		to use Euclidian algorithm to divide by modulo
	2. gcd(a,b){if (b==0) return a; 
				return gcd(b, a%b);}
	3. LCM (Least Common Multiple) 
		lcm(int a, int b) {return a*b/gcd(a,b);}
		LCM sample: 36*48/12=144
*/

// Euclidian algorithm to divide:
int gcd (int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

// A simple solution is to find all prime factors of both numbers.
// If we subtract smaller number from larger (we reduce larger number), GCD doesn’t change.
int gcdRecurs (int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a == b)
		return a;

	if (a > b)
		return gcdRecurs(a-b,b);
	return gcdRecurs(a, b-a);
}

int lcm (int a, int b)
{
	return a*b/gcd(a,b);
}

int 
main (int argc, char** argv)
{
	int a = 36, b = 48;
	cout << "GCD recurs for " << a << " and " << b << " = " << gcdRecurs(a,b) << endl;
	cout << "GCD for " << a << " and " << b << " = " << gcd(a,b) << endl;
	cout << "LCM for " << a << " and " << b << " = " << lcm(a,b) << endl;
	return 0;
}

