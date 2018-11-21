#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int countWaysOfChange(int* coins, int arrSize, int val)
{
	if (val == 0)
		return 1;
	if (val<0)
		return 0;
	if (arrSize<=0 && val >= 1)
		return 0;
	return countWaysOfChange(coins, arrSize-1, val) + countWaysOfChange(coins, arrSize, val-coins[arrSize-1]);
}


int countWaysOfChangeDP(int* coins, int arrSize, int val)
{
	int table [val+1]={0};
	
	// if value is 0
	table [0]=1;
	
	for (int i = 0; i < arrSize; ++i) 
		for (int j = coins[i]; j<=val; ++j)
			table[j] += table[j-coins[i]];
	return table [val];
}


int
main(int argc, char** argv)
{
	int coins[] = {1,2,3,4,5,6,7};
	int arrSize = sizeof(coins)/sizeof(coins[0]);
	int forVal = 4;
	cout << "Recurs solution (top down): For conins 1,2,3,4,5,6,7 we have " <<  countWaysOfChange(coins, arrSize, forVal) 
		<< " different combination to get sum: " << forVal << endl;

	cout << "Iterative solution (bottom up): For conins 1,2,3,4,5,6,7 we have " <<  countWaysOfChangeDP(coins, arrSize, forVal)
                << " different combination to get sum: " << forVal << endl;
	
	return 0;
}
