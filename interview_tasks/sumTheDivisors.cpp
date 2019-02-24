#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 1. Given an integer n, calculate the sum of all divisors of n.
 * Example:
 * the divisors of 8 are 1,2,4 and 8 and 1 + 2 + 4 + 8 = 15
 * The divisors of 7 are 1 and 7, which makes the sum 8.
 * 2. The input number n will be in the range [1, 10^9].
 * 3. Return one number - the sum of divisors of n.
Sample test examples:
Input	Output
8		15
7		8
1		1
1000	2340
 * */

//slow solution
unsigned sum_the_divisorsSlow(unsigned number) {
    unsigned result = 0;
    for (long long i = 1; i <= number; i++) {
    	if ((number % i)==0)
    		result+=i;
    }
    return result;
}

//fast solution
unsigned sum_the_divisorsFast(unsigned number) {
    unsigned result = 0;
    for (long long divisor = 1; divisor * divisor <= number; divisor++) {
        if (number % divisor) {
            continue;
        }
        result += divisor;
        long long anotherDivisor = number / divisor;
        if (anotherDivisor != divisor) {
            result += anotherDivisor;
        }
    }
    return result;
}

int main() {
	const long long N = 1000;
	cout << sum_the_divisorsFast(N) << endl;
	return 0;
}
