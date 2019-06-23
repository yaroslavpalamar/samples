#include <algorithm>
#include <iostream>
#include <vector>


/*
 The task is next:
	Given an array of integers. 
	Find two disjoint contiguous sub-arrays such that the absolute 
	difference between the sum of two sub-array is maximum. 
 	The sub-arrays should not overlap. 
 	example: [2 -1 -2 1 -4 2 8] ans - (-1 -2 1 -4) (2 8), diff = 16 
*/


int computeMaxDiff(std::vector<int> L) {
    int maxLeftNeg[L.size()], maxRightNeg[L.size()], maxLeftPos[L.size()], maxRightPos[L.size()];
    int maxDiff = 0, j;
    int tmp;

    maxLeftNeg[0] = L[0] < 0 ? L[0] : 0;
    maxLeftPos[0] = L[0] > 0 ? L[0] : 0;
    maxRightNeg[L.size() - 1] = L[L.size() - 1] < 0 ? L[L.size() - 1] : 0;
    maxRightPos[L.size() - 1] = L[L.size() - 1] > 0 ? L[L.size() - 1] : 0;
    for (int i = 1; i < L.size(); ++i) {
        maxLeftNeg[i] = (maxLeftNeg[i - 1] + L[i] < 0) ? maxLeftNeg[i - 1] + L[i] : 0;
        maxLeftPos[i] = (maxLeftPos[i - 1] + L[i] > 0) ? maxLeftPos[i - 1] + L[i] : 0;
        j = L.size() - 1 - i;
        maxRightNeg[j] = (maxRightNeg[j + 1] + L[j] < 0) ? maxRightNeg[j + 1] + L[j] : 0;
        maxRightPos[j] = (maxRightPos[j + 1] + L[j] > 0) ? maxRightPos[j + 1] + L[j] : 0;
    }
    for (int i = 0; i < L.size() - 1; ++i) {
        tmp = (i < L.size() - 1) ? 
            std::max(maxLeftPos[i] - maxRightNeg[i + 1], maxRightPos[i + 1] - maxLeftNeg[i])
            : std::max(maxLeftPos[i], - maxLeftNeg[i]);
        maxDiff = std::max(tmp, maxDiff);
    }
    return maxDiff;
}

int main(int argc, char **argv) {
    int ar[] = {2, -1, -2, 1, -4, 2, 8};
    std::vector<int> vec(ar, ar + sizeof(ar) / sizeof(int));
    std::cout << computeMaxDiff(vec) << std::endl;
    return 0;
}


/*#include <iostream>
#include <cmath>
using namespace std;

 

int bestSplit(int* arr, int size) {
	int generalSum = 0;
	for (int i = 0; i< size; i++)
		generalSum += arr[i];

	int runningSum = 0;
	int bestSplitVal = generalSum;//abs(generalSum);
	for (int i = 0; i < size; i++) {
		runningSum += arr[i];
		//if (abs(generalSum - runningSum) > bestSplitVal) {
		if (generalSum - runningSum > bestSplitVal) {
			bestSplitVal = generalSum - runningSum;
		}
	}
	return bestSplitVal;
}

int main()
{
	int arr[] = {2, -1, -2, 1, -4, 2, 8};
	//int arr[] = {2, -4, -5, 3, 6, -1};	
	cout << bestSplit(arr, sizeof(arr)/sizeof(arr[0])) << endl;
	return 0;
}

*/
