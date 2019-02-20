#include <iostream>
using namespace std;

/*
	1. What algorithm doing is compare first elmement with all other and swap with smaller or bigger depends on sorting
		then compare second element, and swap with bigger or smaller then thirth element etc.
		example: [1 0 8 2 4] 1step: minIdx=1 and [0,1,8,2,4];  2step: minIdx=1 0,1,8,2,4; 3step: 0,1,2,8,4; 4step: 0,1,2,4,8.
	2. selection sort function input val arr and size of arr
	3. define int minIdx variable;
	4. in loop for (int i=0; i < arrSize-1; ++i) { minIdx=i;
				for (int j = i+1; j < arrSize; j++)
					if (arr[j] < arr[minIdx]) minIdx=j;
				swap(arr[minIdx], arr[i]);
			}
*/

void swap (int *a, int *b)
{
	int tmp = *a;
	*a=*b;
	*b=tmp;
}

void selectionSort(int* arr, int arrSize)
{
	int minIdx;

	for (int i = 0; i<arrSize-1; ++i) {
		minIdx = i;
		for (int j = i+1; j < arrSize; j++)
			if (arr[j] < arr[minIdx])
				minIdx=j;
		swap(arr[minIdx], arr[i]);
	}
}

void printArr(int* arr, int arrSize) 
{
	for (int i=0; i<arrSize; ++i) {
		cout << arr[i] << endl;
	}
}

int
main (int argc, char** argv)
{	
	int arr[] = {23,31,12,1,2,100,900,7,4,3,2,0,-1,345,45,4,2,4,6,8,9,0,0};
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	

	cout << "Arr size is: " << arrSize << endl;
	selectionSort(arr, arrSize);
	printArr(arr, arrSize);

	return 0;
}

