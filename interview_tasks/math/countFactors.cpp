#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 1. count all integer factors of a positive integer number N, including 1 and the number itself.
 * 2. For example for 12 there are 6 such factors: 1, 2, 3, 4, 6, 12.
 * 3. In this task N will be in the range [1, 10^12].
 * 4. Function should return number of all possible factors of N.
 * Example for 12 it is 6
 * */

int gcd (long long a, long long b, int& countFactors)
{
	if (b==0) {
		countFactors++;
		return a;
	}
	return gcd (a, a%b, countFactors);
}

//slow solution
int count_numbers_factorsSlow(long long n) {
    int result = 0;
    for (long long i = 1; i <= n; i++) {
    	if ((n % i)==0)
    		result++;
    }
    return result;
}

//fast solution
int count_numbers_factorsFast(long long n) {
    int result = 0;
    long long i;
    for (i = 1; i*i < n; i++) {
    	if ((n % i)==0) {
    		result+=2;
    	}
    }
    if (i*i==n)
    	result++;
    return result;
}

int main() {
	const long long N = 12;
	cout << count_numbers_factorsFast(N) << endl;
	return 0;
}
