#include <iostream>
using namespace std;

/*
	1. example: [4,0,5,2] 1step: [0,4,5,2], [0,4,5,2], [0,4,2,5]; 
		2step: [0,4,2,5], [0,2,4,5]. 3step: [0,2,4,5]
	2. bubble sort algo in loop go through all values 
	3. inside second loop go through 0 val to arrSize -i -1
	4. if arr[i] > arr[j+1] swap;
*/

void swap (int *a, int *b)
{
	int tmp = *a;
	*a=*b;
	*b=tmp;
}

void bubbleSort(int* arr, int arrSize)
{
	for (int i=0; i < arrSize-1; ++i) {
		for (int j=0; j<arrSize-i-1; ++j) {
			if (arr[j] > arr[j+1])
				swap(arr[j], arr[j+1]);
		}
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
	bubbleSort(arr, arrSize);
	printArr(arr, arrSize);

	return 0;
}

