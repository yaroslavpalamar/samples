#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int minNumCoins(int* coins, int arrSize, int val)
{
	int table[val+1];
	table[0]=0;
	for (int i = 1; i <= val; ++i) {
		table[i] = INT_MAX;
	}
	

	for (int i=1; i <= val; ++i) {
		for (int j=0; j<arrSize; ++j) {
			if (coins[j] <= i) {
				int subRes=table[i-coins[j]];
				if (subRes != INT_MAX && subRes+1<table[i]) {
					table[i] = subRes+1;
				}
			}
		}
	}
	
	return table[val];
}

int
main(int argc, char** argv)
{
	int coins[] = {9,6,5,1};
	int arrSize = sizeof(coins)/sizeof(coins[0]);
	int forVal = 11;
	cout << "Minimum coins required for value 11 is:"
		<< minNumCoins(coins, arrSize, forVal) << endl;
	
	return 0;
}
