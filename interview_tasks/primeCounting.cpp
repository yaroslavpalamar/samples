#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

/*
 * 1. For N=10, the prime numbers, which are less than or equal to 10 are: 2, 3, 5, 7.
 * The function must return 4.
 * 2. For N=31, the prime numbers are: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31.
 * The function must return 11..
 * */

int prime_counting(int n) {
	int result=0;
    for (long long i = 2; i <= n; i++) {
    	if ((n % i)==0) {
    		result++;
    	}
    }
    return result;
}

int main() {
	const long long N = 31;
	//const long long N = 64;
	cout << prime_counting(N) << endl;
	return 0;
}
