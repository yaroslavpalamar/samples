#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 1. If a fraction has numerator N and denominator D,
 * then it is simple if N and D don’t have any common divisors other than 1.
 * 2. Es example:
 * The fraction 3/7 cannot be simplified because 3 and 7 don’t have any common divisors other than 1.
 * The fraction 8/24 on the other hand, can be simplified to 1/3.
 * 3. The integers N and D will be in the range [1, 1,000,000,000].
 * 4. 	SAMPLE INPUT
		77 22
		SAMPLE OUTPUT
		7 2
 * */

// Euclidian algorithm to divide:
int gcd (int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

void simplify_fraction(int numerator, int denominator, int result[2]) {
	const int GCD  = gcd(denominator, numerator);
    result[0] = numerator/GCD;
    result[1] = denominator/GCD;
}

int main() {
	const int numerator = 77;
	const int denominator = 22;
	int result [2];
	simplify_fraction(numerator, denominator, result);
	cout << result[0] << " , " << result[1] << endl;
	return 0;
}
