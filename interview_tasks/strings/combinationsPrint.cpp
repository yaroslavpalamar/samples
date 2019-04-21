#include <iostream>
using namespace std;  
  
/* index: Current index in data[]  
r: Size of a combination to be printed */
void combinationUtil(int arr[], int data[],  
                    int start, int end,  
                    int index, int r)  
{
    // Current combination is ready 
    // to be printed, print it  
    if (index == r)  
    {  
        for (int j = 0; j < r; j++)  
            cout << data[j] << " ";  
        cout << endl;  
        return;  
    }
  
    // replace index with all possible  
    // elements. The condition "end-i+1 >= r-index" 
    // makes sure that including one element  
    // at index will make a combination with  
    // remaining elements at remaining positions  
    for (int i = start; i <= end &&  
        end - i + 1 >= r - index; i++)  
    {  
        data[index] = arr[i];  
        combinationUtil(arr, data, i+1,  
                        end, index+1, r);  
    }  
}
  
void printCombination(int arr[], int n, int r)  
{ 
	//result array
	int data[r];  
	combinationUtil(arr, data, 0, n-1, 0, r);
} 



////////////////////////////////////////////////////
/* arr[] ---> Input Array  
n ---> Size of input array  
r ---> Size of a combination to be printed  
index ---> Current index in data[]  
data[] ---> Temporary array to store current combination  
i ---> index of current element in arr[] */
void pascalCombinationUtil(int arr[], int n, const int elemSiz,  
                    int iData, int data[], int iArr)  
{  
    // Current cobination is ready, print it  
    if (iData == elemSiz)  
    {  
        for (int j = 0; j < elemSiz; j++)  
            cout << data[j] << " ";  
        cout << endl;  
        return;
    }  
  
    // When no more elements are there to put in data[]  
    if (iArr >= n) 
        return;  
  
    // current is included, put next at next location  
    data[iData] = arr[iArr];  
    pascalCombinationUtil(arr, n, elemSiz, iData + 1, data, iArr+1);  
  
    // current is excluded, replace it with next (Note that  
    // i+1 is passed, but iData is not changed)  
    pascalCombinationUtil(arr, n, elemSiz, iData, data, iArr+1);  
}   

void pascalPrintCombination(int arr[], int aSiz, const int elemSiz)  
{  
    int data[elemSiz];
    pascalCombinationUtil(arr, aSiz, elemSiz, 0, data, 0);
} 

int main()  
{  
	int arr[] = {1, 2, 3, 4, 5};  
	const int elSiz = 3;  
	int n = sizeof(arr)/sizeof(arr[0]);  
    	printCombination(arr, n, elSiz);
	
	cout << "Pascal impl" << endl;
	pascalPrintCombination(arr, n, elSiz);
}

