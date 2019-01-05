#include <iostream>
using namespace std;

/*
	knapsack problem implementation
	1. we have two integers array one represent value val[0..n-1] other weight wt[0..n-1]. 
	2. Also we have int W which represen knapsack capacity 
	3. find max value subset of val[] such that sum of waight from wt[] which smaller or equal to W

val[]={60,100,120};
wt[]={10,20,30};
W=50;

Weight, Value
10,     60
20,     100
30,     120

Need to calculate all combinations of values
Weight 30+20+10>50 can't be inside val W.
Weight = 20+10; Val 100+60
Weight = 30+10; Val 120+60
Weight = 30+20; Val 120+100

Result 220 becaus 30+20=50

*/

// A utility function that returns maximum of two integers 
int max(int a, int b) { return (a > b)? a : b; } 
  
// Returns the maximum value that can be put in a knapsack of capacity W 
/*
			K(3, 2)         ---------> K(n, W)
                   /            \
                 /                \
            K(2,2)                  K(2,1)
          /       \                  /    \
        /           \              /        \
       K(1,2)      K(1,1)        K(1,1)     K(1,0)
       /  \         /   \          /   \
     /      \     /       \      /       \
K(0,2)  K(0,1)  K(0,1)  K(0,0)  K(0,1)   K(0,0)
*/

int knapSackRec(int W, int wt[], int val[], int n) 
{ 
   // Base Case 
   if (n == 0 || W == 0) 
       return 0; 
  
   // If weight of the nth item is more than Knapsack capacity W, then 
   // this item cannot be included in the optimal solution 
   if (wt[n-1] > W) 
       return knapSackRec(W, wt, val, n-1); 
  
   // Return the maximum of two cases:  
   // (1) nth item included  
   // (2) not included 
   else 
	return max( val[n-1] + knapSackRec(W-wt[n-1], wt, val, n-1), knapSackRec(W, wt, val, n-1));
}

// Returns the maximum value that can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int K[n+1][W+1]; 
  
   // Build table K[][] in bottom up manner 
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][W]; 
}
  
// Driver program to test above function 
int main() 
{ 
	int val[] = {60, 100, 120}; 
	int wt[] = {10, 20, 30}; 
	int W = 50; 
	int n = sizeof(val)/sizeof(val[0]); 
	cout << "Recursive solution:" << endl;
	cout << knapSackRec(W, wt, val, n) << endl;
    
	cout << "Dynamic programming solution:" << endl;
	cout << knapSack(W, wt, val, n) << endl;

	return 0;
}

