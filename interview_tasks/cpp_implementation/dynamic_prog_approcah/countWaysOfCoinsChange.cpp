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

int
main(int argc, char** argv)
{
	int coins[] = {1,2,3,4,5,6,7};
	int arrSize = sizeof(coins)/sizeof(coins[0]);
	int forVal = 4;
	cout << "For conins 1,2,3,4,5,6,7 we have " <<  countWaysOfChange(coins, arrSize, forVal) 
		<< " different combination to get sum: " << forVal << endl;
	
	return 0;
}
