#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

/*
 * 1. Given an integer N, for which 2 <= N <= 10^12 find its prime factors.
 * 2. For N=20 the prime decomposition is 20 = 2 * 2 * 5, so you must return 2, 2, 5.
For N=64 the prime decomposition is 64 = 2 * 2 * 2 * 2 * 2 * 2, result must be 2, 2, 2, 2, 2, 2.
For N=1105 the prime decomposition is 1105 = 5 * 13 * 17, result must be 5, 13, 17.
 * */

//slow solution
vector<long long> all_prime_factors(long long n) {
	vector<long long> result;
    for (long long i = 2; i <= n; i++) {
    	while ((n % i)==0) {
    		result.push_back(i);
    		n/=i;
    	}
    }
    return result;
}

//fast solution
vector<long long> all_prime_factorsFast(long long n) {
	vector<long long> result;
    for (long long i = 2; i <= sqrt(n); i++) {
    	while ((n % i)==0) {
    		result.push_back(i);
    		n/=i;
    	}
    }
    if (n != 1) {
        result.push_back(n);
    }
    return result;
}

int main() {
	//const long long N = 9901;
	//const long long N = 1105;
	//
	const long long N = 20;
	//const long long N = 64;
	vector<long long> result = all_prime_factorsFast(N);
	for (int i = 0; i < result.size(); i++ )
		cout << all_prime_factors(N)[i] << endl;
	return 0;
}
