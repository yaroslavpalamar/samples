#include <iostream>
#include <vector>
using namespace std;

/*
	1. list of n integers. n < 90 000
	2. for [4] correct answer is [4].
	3. For [200, 2, 7, 77, 11, 14, 4, 0, 19] crrect answer 2,7,11,14,19 or 2,7,11,12,19
	4. Does the array contain unique numbers or can they be repeated? can be repeated.
	5. What should I return?
	6. If there are multiple solutions to the problem, which one should be returned?
	7. What should I do/return if the input is invalid / does not match the constraints?

	Pseudocode:
		recurs
		input[200,2,7,77,11,14,4,0,19];
		vector[0]=input[0];  // 200
		savedVals[];
		if (input[i] < [i-1])
			vector.push_back(input[i]);
		else
			longest_increasing_subsequence();
		...
*/

vector<int> longest_increasing_subsequence(vector<int> sequence) {
    vector<int> result = {0};
    return result;
}

int main() {
	vector<int> test = {200,2,7,77,11,14,4,0,19};
	longest_increasing_subsequence(test);
	return 0;
}
