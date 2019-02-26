#include <iostream>
#include <vector>
using namespace std;

/*
 * 1. For N=10, the prime numbers, which are less than or equal to 10 are: 2, 3, 5, 7.
 * The function must return 4.
 * 2. For N=31, the prime numbers are: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31.
 * The function must return 11..
 * */

int prime_counting(int n) {
	if (n < 2) {
		return 0;
	}
	vector<bool> isPrime(n+1, true);
	int result = 0;
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			result += 1;
			// This is needed to avoid type overflows on j
			for (long long j = (long long)i*i; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}
	return result;
}

int main() {
	const long long N = 10;
	//const long long N = 64;
	cout << prime_counting(N) << endl;
	return 0;
}
