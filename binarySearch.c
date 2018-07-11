/* C implementation for Binary Search (recursive and iterative) */
#include <stdio.h>
 
/* A recursive binary search function. Returns location of x in given array arr[l..r] 
 * otherwise -1 */
int binarySearchRecursive(int arr[], int l, int r, int val)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
 
        // If the element is present at the middle return it
        if (arr[mid] == val)  
            return mid;
 
        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > val) 
            return binarySearchRecursive(arr, l, mid-1, val);
 
        // Else the element can only be present in right subarray
        return binarySearchRecursive(arr, mid+1, r, val);
   }
 
   return -1;
}

int binarySearchIterative(int arr[], int l, int r, int val)
{
    while (l <= r)
    {
        int m = l + (r-l)/2;
 
        // Check if val is present at mid
        if (arr[m] == val)
            return m;
 
        // If val greater, ignore left half
        if (arr[m] < val)
            l = m + 1;
 
        // If val is smaller, ignore right half
        else
            r = m - 1;
    }
 
    return -1;
}

/* A iterative binary search function.
 * otherwise -1 */
int main(void)
{
   int arr[] = {2, 3, 4, 6, 34, 37, 39, 67, 77, 88};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int val = 88;
   int result = binarySearchIterative(arr, 0, n-1, val);
   if (result == -1) {
	   printf("Element is not present in the array");
   } else {
	   printf("Element is present at index %d", result);
   }
   return 0;
}
