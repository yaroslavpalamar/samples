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
 
int main(void) 
{
	char arr[]={4,6,5,4,3,3, 7,7,7,5,5,5 ,5,8,2,10};
	int arrLength = sizeof(arr);

	for(int n=0; n < arrLength; n++)
	printf("%d ",arr[n]);
	printf("\n");

	removeDuplFromArray(arr, arrLength);
	
	for(int n=0; n < strlen(arr); n++)
	printf("%d ",arr[n]);
	return 0;
}

