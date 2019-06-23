#include <iostream>
#include <climits>
using namespace std;

/* Maximum subarrya problem:
 *Possible solution is Jay Kadane algorithm:
	We have:
		array arr[];
	init:
		maxSoFar = 0;
		maxEndingHere = 0;
	loop for each element of array:
		maxEndingHere = maxEndingHere + arr[i];
		if (maxEndingHere < 0)
			maxEndingHere = 0;
		if (maxSoFar < maxEndingHere)
			maxSoFar = maxEndingHere;
	return maxSoFar;
 */

/*
 * FYI: Dynamic programming solve next two problems:
 * 1) Overlapping Subproblems (don't calculate twice, just store data in structures)
 * 2) Optimal Substructure (possibility to split complex problem to many simple problems, example Bellaman-Ford algo)
 */


int maxSubArraySum(int arr[], int size)
{
	int maxSoFar = INT_MIN;
	int maxEndingHere = 0;

	for (int i = 0; i < size; ++i) {
		maxEndingHere = maxEndingHere + arr[i];
		if (maxSoFar < maxEndingHere)
			maxSoFar = maxEndingHere;

		if (maxEndingHere < 0)
			maxEndingHere = 0;
	}

	return maxSoFar;
}

int
main(int argc, char** argv)
{
	int arr[] = {-7, -2, 4, -1, -2, 1, 5, -3};
	int size = sizeof(arr)/sizeof(arr[0]);
	int maxSum = maxSubArraySum(arr, size);
	cout << "Max contigious sum is " << maxSum;

        return 0;
}

