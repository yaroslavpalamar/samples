#include <iostream>
using namespace std;

void swap(int *a, int *b) 
{
	int tmp = *a;
	*a=*b;
	*b=tmp;
}

// function place the pivot in correct position and
// sort smaller tnen pivot to the left and greater
// than pivot to the rigth of pivot.
int partition (int * arr, int low, int high)
{
	int pivot = arr[high]; //pivot
	cout << "\npivot: " << pivot << endl;
	
	int iSm = (low -1); // index of smaller element

	cout << " low: " << low << " high: " << high << endl;	

	for (int jBig = low; jBig <= high-1; jBig++) {	
		//if current element is smaller than or equal to pivot
		if (arr[jBig] <= pivot) {
			iSm++; // increment index of smaller element
			cout << " arr[iSm] " <<arr[iSm]<<" arr[jBig] " << arr[jBig] << " ;";
			swap(&arr[iSm], &arr[jBig]);
		}
	}
	cout << "\n !PIV[iSm+1] " << arr[iSm+1] << " arr[high] " << arr[high] << " ;";
	swap (&arr[iSm+1], &arr[high]);
	return (iSm+1);
}


// low is first index of arrey, high it is last index of arrey
void quickSort(int* arr, int low, int high) 
{
	if (low < high)
	{
		int pivot = partition (arr, low, high);
		
		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pivot-1);
		quickSort(arr, pivot+1, high);
	}
}

void printArr(int* arr, int arrSize)
{
	for (int i=0; i< arrSize; ++i) {
		cout << arr[i] <<" ";
	}
	cout << endl << endl;
}

int
main (int argc, char** argv) 
{
	int arr[] = {1,2,3,4,44,2,34,23,1,4,0,-2};
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	cout << "print arr before sorting: " << endl;
	printArr(arr, arrSize);

	quickSort(arr, 0, arrSize-1);
	
	cout << endl << "print result arr after sorting: " << endl;
	printArr(arr, arrSize);
}
