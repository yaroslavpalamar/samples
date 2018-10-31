#include <iostream>
using namespace std;

void insertionSort(int* arr, int arrSize)
{
	int key, j;
	for (int i; i< arrSize; ++i) {
		key=arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1]=key;
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
	int arr[] = {23,31,12,1,2,100,900};
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	
	insertionSort(arr, arrSize);
	printArr(arr, arrSize);

	return 0;
}

