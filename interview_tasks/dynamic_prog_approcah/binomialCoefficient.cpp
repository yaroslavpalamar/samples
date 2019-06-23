#include <iostream>
#include <cstring>
using namespace std;
/*n-choose-k problem, binomial coefficient:
 * Write a function that takes two parameters n and k 
 * and returns the value of Binomial Coefficient C(n, k). 
 * */

int binomCoeffRecur(int n, int k)
{
	if (k==0 || k==n)
		return 1;
	return binomCoeffRecur(n-1, k-1) + binomCoeffRecur(n-1, k);
}

int binomCoeffDP(int n, int k)
{
	int C[n+1][k+1];

	for (int i = 0; i <= n; i++) 
	{
		// bottom up solution
		for (int j = 0; j <=min(i,k); j++)
		{
			if (j == 0 || j == i)
				C[i][j] = 1;
			else 
				C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}
	return C[n][k];
}

int binomCoeffDPOptimized(int n, int k)
{
	int C[k+1];
	memset(C, 0, sizeof(C));

	C[0] = 1; //nC0 = 1

	for (int i = 1; i <= n; i++) 
	{
		for (int j = min(i,k); j > 0; j--)
		{
			C[j] = C[j] + C[j-1];
		}
	}
	return C[k];
}


int
main(int argc, char** argv)
{
	int n = 5, k = 2;
	
	cout << "Recurs solution: val of C(" << n << "," << k << ") is " << binomCoeffRecur(n, k) << endl;
	cout << "DP solution: val of C(" << n << "," << k << ") is " << binomCoeffDP(n, k) << endl;
	cout << "DP optimized solution: val of C(" << n << "," << k << ") is " << binomCoeffDPOptimized(n, k) << endl;
	return 0;
}

