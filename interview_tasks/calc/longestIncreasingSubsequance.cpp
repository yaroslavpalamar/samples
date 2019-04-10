#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	1. list of n integers. n < 90 000
	2. for [4] correct answer is [4].
	3. For [200, 2, 7, 77, 11, 14, 4, 0, 19] crrect answer 2,7,11,14,19 or 2,7,11,12,19
	4. Does the array contain unique numbers or can they be repeated? can be repeated.
	5. What should I return?
	6. If there are multiple solutions to the problem, which one should be returned?
	7. What should I do/return if the input is invalid / does not match the constraints?

	As example: L(i) be the length of the LIS ending at index i such that arr[i] is the last element of the LIS
	Then, L(i) can be recursively written as:
	L(i) = 1 + max( L(j) ) where 0 < j < i and arr[j] < arr[i]; or
	L(i) = 1, if no such j exists.

	Pseudocode:
		input[200,2,7,77,11,14,4,0,19];
		if input size 0 return empty vector
		if input size 1 return first element 
		create array lis[seqSize] with size of input vector
		int maxVal - save max value in input vector here
		int indWithMaxVal - save index that point to max val in input vector
		for (int i = 0; i < seqSize; i++) each element in vector
			set lis[i] to 1 //200=1, 199=1, 198=1, 197=1, 2=1, 7=2, 77=2.	
			for ( int j=0; j < i; j++) { // recalculate length for every element in subsequence
				if (input[i] > input[j] && lis[i] < lis[j]+1){ //7>2&&2>1,77>7&&....11>7,11>2
					lis[i]=lis[j]+1 //7:2; 11:2,11:3 (for 11 will go to this block two times.)
					if (lis[i]>maxVal) {
						maxVal=lis[i]
						indWithMaxVal =i 
					}
				}
			}
		result.push_back(input(indWithMaxVal--))  push max element to resultand decrement 
							  index to next value to find less value
		maxVal-- one value in result so decrement maxVal
		for (int i = indWithMaxVal; i >=0;i--) {
			if (lis[i]==maxVal)
				result.insert(sequence[i])
				maxVal--;
		}
		return result;
*/

vector<int> longest_increasing_subsequence(vector<int> sequence) {
	vector<int> result;
	int seqSize = sequence.size();
	if (seqSize == 0)
		return result;
	if (seqSize == 1) {
		result.push_back(sequence.at(0));
		return result;
	}
	int lis[seqSize]; 
	int maxVal = 0;
	int indWithMaxVal = 0;
	for (int i = 0; i < seqSize; ++i) {
		lis[i]=1;
		for (int j = 0; j < i; ++j) {
			if (sequence[i] > sequence[j] && lis[i] < lis[j]+1) {
				lis[i]=lis[j]+1;
				if (lis[i] > maxVal) {
					maxVal = lis[i];
					indWithMaxVal=i;
				}
			}
		}
	}
	result.push_back(sequence[indWithMaxVal]);
	if (maxVal==0) // just for optimization
		return result;
	--indWithMaxVal;
	--maxVal;

	for (int i = indWithMaxVal; i >= 0; --i) {
		if (lis[i]==maxVal) {
			result.insert(result.begin(), sequence[i]);
			--maxVal;
		}
	}
	return result;
}

int main() {
	vector<int> test = {200,199,198,197,2,7,77,11,14,4,0,19,19};
	//vector<int> test;
	//vector<int> test{2};
	//vector<int> test{3,3};
	vector<int> result = longest_increasing_subsequence(test);
	int i=0;
	for (int val:result) {
		cout << result[i++] << endl;
	}
	return 0;
}
