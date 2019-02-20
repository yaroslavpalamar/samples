#include <iostream>
using namespace std;

/*
	insertion sort example: [4,2,5,0] 1.step: key=2, iP=0; 2,4,5,0  2.step: key=5, iP=1 [2,4,5,0]
						3.setp: iP=2, key=0 [2,4,5,5]; -> iP=1 [2,4,4,5]-> iP=0 [2,2,4,5] ->iP=-1 [0,2,4,5]
	1. define two variable keyVal and iPrev
	2. loop from 1 element to arrSize for(i=1;i<arrSize;i++)
		save element to keyVal=arr[i];
		in iPrev seve index to prev element
			Now you can move back to the beginning array and compare key Value with prevous
			if less than previous just swap the values 
				while (iPrev >= 0 && arr[iPrev] > keyVal) {arr[iPrev+1] = arr[iPrev];
										iPrev = iPrev-1;}
			arr[iPrev+1]=keyVal;
*/
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

