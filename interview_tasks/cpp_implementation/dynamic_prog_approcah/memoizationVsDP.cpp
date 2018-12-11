#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 1000;

int lcsRecurs(string X, string Y, int m, int n) 
{ 
	if (m == 0 || n == 0) 
		return 0; 
  
	if (X[m - 1] == Y[n - 1]) 
		return 1 + lcsRecurs(X, Y, m - 1, n - 1); 
	else
		return max(lcsRecurs(X, Y, m, n - 1), lcsRecurs(X, Y, m - 1, n)); 
}

// Longest Common Subsequence (LCS), DP using memoization:
int lcsMemoizRecurs(string X, string Y, int m, int n, int dp[][MAX])
{
	//base case
	if (m == 0 || n == 0)
		return 0;
	
	//if the same state has already been computed
	if (dp[m - 1][n - 1] != -1)
		return dp[m - 1][n - 1];

	// if equal then store value of funct call
	if (X[m - 1] == Y[n - 1]) {
		// store it in arr to avoid further repetitive 
		// work in future function calls
		dp[m - 1][n - 1] = 1 + lcsMemoizRecurs(X, Y, m - 1, n - 1, dp); 
		return dp[m - 1][n - 1];
	} else {
		//store it in arr to avoid further repetitive work in future funct calls
		dp[m - 1][n - 1] = max(lcsMemoizRecurs(X, Y, m, n - 1, dp), lcsMemoizRecurs(X, Y, m - 1, n, dp)); 
		return dp[m - 1][n - 1];
	}
}


int lcsTab( string X, string Y, int m, int n ) 
{ 
	int L[m+1][n+1]; 
	int i, j;
	/* Following steps build L[m+1][n+1] in bottom up fashion. Note  
	*       that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	for (i=0; i<=m; i++) 
	{
		for (j=0; j<=n; j++) { 
			if (i == 0 || j == 0) 
				L[i][j] = 0; 
   			else if (X[i-1] == Y[j-1]) 
				L[i][j] = L[i-1][j-1] + 1;
			else
        			L[i][j] = max(L[i-1][j], L[i][j-1]); 
		}
	}
     
	/* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
	return L[m][n];
}

int main ()
{
	string s1 = "AGGTAB"; 
	string s2 = "GXTXAYB"; 
  
	// Find the length of string 
	int lenS1 = s1.length(); 
	int lenS2 = s2.length();         
	cout << "Length of LCS with just recursion solution: " << lcsRecurs(s1, s2, lenS1, lenS2) << endl; 

	int dp[lenS1][MAX]={0};
	// assign -1 to all positions 
	memset(dp, -1, sizeof(dp)); 
	cout << "Length of LCS with memoization solution: " << lcsMemoizRecurs(s1, s2, lenS1, lenS2, dp) << endl;	


	cout << "Length of LCS with just tabulation solution: " << lcsTab(s1, s2, lenS1, lenS2) << endl;

	return 0;
}

