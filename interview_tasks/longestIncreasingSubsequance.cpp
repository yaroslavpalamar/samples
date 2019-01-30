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
		for (int i =0; i< seqSize;i++) each element in vector	
			set lis[i] to 1
			for ( int j=0; j < i;j++)
				if (input[i] > input[j] && lis[i] < lis[j]+1)
					lis[i]=lis[j]+1

			int lastGoodVal=arr[0];
			for (int i = 0 ; i < seqSize; i++)
				if (lastGoodVal+1==lis[i])
					result.push_back(sequence.at(i))
					lastGoodVal=arr[i];
					
		...
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
	lis[0] = 1;
	int maxVal = 0;
	int indWithMaxVal = 0;
	for (int i = 0; i < seqSize; i++) {
		lis[i]=1;
		for (int j = 0; j < i; j++) {
			if (sequence[i] > sequence[j] && lis[i] < lis[j]+1) {
				lis[i]=lis[j]+1;
				if (lis[i] > maxVal) {
					maxVal = lis[i];
					indWithMaxVal=i;
				}
			}
		}
	}
	for (int i = indWithMaxVal; i >= 0; --i) {
		if (result.empty()) {
			result.push_back(sequence[i]);
			maxVal--;
			continue;
		}
		if (lis[i]==maxVal) {
			result.push_back(sequence[i]);
			maxVal--;
		}
	}
	reverse(result.begin(), result.end());
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
