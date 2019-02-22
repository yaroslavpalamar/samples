#include <iostream>
using namespace std;

/*	
	merge sort iterative impl:
	1. example: [4,5,0,2] 
	2. iterMergeSort (for(int curSize=1; curSize<=arrSize-1; curSize=2*CurSize){    //1step: curSize=1; 2step: curSize=2;
		for (int leftStart=0; leftStart < arrSize-1; leftStart += 2*curSize) { //1step: lS=0 2step: lS=2; 3step:lS=0; 
			int mid = leftStart + curSize-1; //1:mid = 0 2:mid=2; 3:mid=1
			int rightEnd = min(leftStart + 2*curSize - 1, arrSize - 1); //1: rightEnd=1; 2: rightEnd=3 3: rightEnd=3
			mergeParts(arr, leftStart, mid, rightEnd); }
		}
	
	merge sort recurs impl:
	1. example: [4,5,0,2]
	2. Call function mergeSortRecurs(arr, 0, arrSize-1); //iLeft = 0; iRight = 3;
	3. if (iLeft < iRight) {
		int iMed = iLeft + (iRight-iLeft)/2; // 1s: iMid=1 2s: iMid=2
		mergeSortRecurs(arr, iMed+1, iRight); // 1s: 2,3 2s: 3,3..
		mergeSortRecurs(arr, iLeft, iMed); // 1s: iL=2 iM=2
		mergeParts (arr, iLeft, iMed, iRight);
	} 
*/

void mergeParts(int* arr, int iLeft, int iMed, int iRight)
{
	// copy data to to the tmp subarreys
	int lArrSize = iMed-iLeft+1;
	int rArrSize = iRight-iMed;
	int subArrL[lArrSize];
	int subArrR[rArrSize];
	for (int i=0; i<lArrSize;++i) {
		subArrL[i]=arr[i+iLeft];
	}
	for (int i=0; i<rArrSize;++i) {
		subArrR[i]=arr[i+iMed+1];
	}

	// merge data	
	int iL = 0;
	int iR = 0;
	int iRes = iLeft;
	cout << "iLeft: " << iLeft << " iMed: " <<  iMed << " iRight:" <<  iRight <<endl;
	cout << "valL " << subArrL[iL] << " valR " << subArrR[iR] << endl;
	while (iL < lArrSize && iR < rArrSize) {
		if (subArrL[iL]<=subArrR[iR]) {
			arr[iRes] = subArrL[iL];
			iL++;
		} else {
			arr[iRes] = subArrR[iR];
			iR++;
		}
		iRes++;
	}

	// copy remaining elements 
	while(iL<lArrSize) {
		arr[iRes++]= subArrL[iL++];
	}
	while(iR<rArrSize) {
		arr[iRes++]= subArrR[iR++];
	}
}

void mergeSortRecurs(int *arr, int iLeft, int iRight) 
{
	if (iLeft < iRight) 
	{
		int iMed = iLeft + (iRight-iLeft)/2;
		mergeSortRecurs(arr, iMed+1, iRight);
		mergeSortRecurs(arr, iLeft, iMed);
		mergeParts (arr, iLeft, iMed, iRight);
	}
}

int min(int x, int y) 
{ 
	return (x<y)?x:y; 
}

void printArr(int* arr, int arrSize);
void mergeSortIterative(int *arr, int arrSize)
{
	for (int curSize=1; curSize <= arrSize-1; curSize = 2*curSize) {
		//cout << "test"<< curSize << endl;
		for (int leftStart=0; leftStart < arrSize-1; leftStart += 2*curSize) {
			int mid = leftStart + curSize-1;
			int rightEnd = min(leftStart + 2*curSize - 1, arrSize - 1);
			mergeParts(arr, leftStart, mid, rightEnd);
		}
	}
}

void printArr(int* arr, int arrSize)
{
	for (int i=0; i< arrSize; ++i) {
		cout << arr[i]<<" ";
	}
	cout << endl << endl;
}

int
main (int argc, char** argv) 
{
	//int arr[] = {1,3,2,5,44,2,34,54,7,678,-1,35,45,345};
	int arr[] = {4,3,90,7,2,0,8,5};
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	cout << "print arr before merge: " << endl;
	printArr(arr, arrSize);
	//mergeSortRecurs(arr, 0, arrSize-1);
	mergeSortIterative(arr, arrSize);

	cout << endl << "print result arr after last merge: " << endl;
	printArr(arr, arrSize);
}

