#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* O(n log n) function example to remove duplicated data in array */ 
 
int cmpfunc (const void * e1, const void * e2)
{
	return (strcmp(e1, e2));
}


void removeDuplFromArray(char* arr, int arrLength) {
	qsort(arr, arrLength, sizeof(arr[0]), cmpfunc);
	
	char* first = arr;
	char* last = arr+arrLength;
	char* result = first;
	
	while (++first != last) {
		if (!(*result == *first)) 
			*(++result)=*first;		
	}
	(*++result) = '\0';
}

int foundInArr(char val, char* arr, int arrLength) 
{
	for (int i = 0; i < arrLength; ++i) {
		if (val == arr[i])
			return 1;
	}
	return 0;
}

void removeDuplFromArray2(char* arr, int arrLength) {
	char checkArr[255]={0};
	char *first = arr;
	char* last = arr+arrLength;
	char* result = first;

	int i=0;
	checkArr[i++] = *result;
	while (++first != last) {
		if (!foundInArr(*first, checkArr, strlen(checkArr))) {
			checkArr[i++]=*(first);
			*(++result)=*first;
		}
	}
	(*++result) = '\0';
}
 
int main(void) 
{
	printf ("Original array:\n");
	char arr[]={4,6,5,4,3,3,7,7,7,5,5,5,5,8,2,10};
	int arrLength = sizeof(arr);

	for(int n=0; n < arrLength; n++)
	printf("%d ",arr[n]);
	printf("\n");

	printf ("Call first function to remove dupl from arr:\n");
	removeDuplFromArray(arr, arrLength);
	for(int n=0; n < strlen(arr); n++)
		printf("%d ",arr[n]);

	
	char arr2[]={4,6,5,4,3,3, 7,7,7,5,5,5 ,5,8,2,10};
	printf ("\nCall second function to remove dupl from arr:\n");
	removeDuplFromArray2(arr2, arrLength);
	for(int n=0; n < strlen(arr2); n++)
		printf("%d ",arr2[n]);
	return 0;
}

