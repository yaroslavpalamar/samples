#include <iostream>
using namespace std;

/* This function takes last element as pivot, places 
 * the pivot element at its correct position in sorted 
 * array, and places all smaller (smaller than pivot) 
 * to left of pivot and all greater elements to right 
 * of pivot */


void swap(int *a, int *b) 
{
	int tmp = *a;
	*a=*b;
	*b=tmp;
}

int partition (int * arr, int low, int high)
{
	int pivot = arr[high]; //pivot
	int i = (low -1); // index of smaller element

	for (int j = low; j <= high -1; j++) {	
		//if current element is smaller than or equal to pivot
		if (arr[j] <= pivot) {
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap (&arr[i+1], &arr[high]);
	return (i+1);
}


//low start index, high end index
void quickSort(int* arr, int low, int high) 
{
	if (low < high)
	{
		int pi = partition (arr, low, high);
		
		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi -1);
		quickSort(arr, pi+1,high);
	}
}

void printArr(int* arr, int arrSize)
{
	for (int i=0; i< arrSize; ++i) {
		cout << arr[i] << endl;
	}
}

int
main (int argc, char** argv) 
{
	int arr[] = {1,2,3,4,44,2,34,54,7,678,23,1,4,0,-2};
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	quickSort(arr, 0, arrSize-1);
	printArr(arr, arrSize);
}
