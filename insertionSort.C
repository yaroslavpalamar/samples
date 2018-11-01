#include <iostream>
using namespace std;

void insertionSort(int* arr, int arrSize)
{
	int keyVal, iPrev;
	for (int i=1; i< arrSize; ++i) {
		// save element for compare
		keyVal=arr[i];
		iPrev = i - 1;

		// move back to the beginning array and compare key Value with prevous
		// if less tnan previous just swap the values
		while (iPrev >= 0 && arr[iPrev] > keyVal)
		{
			arr[iPrev+1] = arr[iPrev];
			iPrev = iPrev-1;
		}
		arr[iPrev+1]=keyVal;
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
	insertionSort(arr, arrSize);
	printArr(arr, arrSize);

	return 0;
}

