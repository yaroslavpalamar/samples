#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ALLOWED_ARGS_NUM 3

/*
Input: num1 = "3", num2 = "40"
Output: "120"
*/


char* multiply(const char* num1, const char* num2){
	if(*num1=='0' || *num2=='0')
		return "0";
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int len = len1+len2;
	char *arr = (char*)calloc(sizeof(char)*(len+1), sizeof(char));
	
	if (!arr) {
		printf ("Memory can't be allocated.");
		return NULL;
	}

	// multiply and save result in arr but not in ascii format.
	for(int i=len1-1; i > -1; i--) {
		for(int j=len2-1; j > -1; j--) {
			arr[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
			printf("1, %d\n",arr[i+j+1]);
			arr[i+j] += arr[i+j+1]/10;
			arr[i+j+1] %= 10;
			printf("2, %d\n",arr[i+j]);
			printf("3, %d\n",arr[i+j+1]);
		}
	}

	// ignore first byte if it 0.
	int i = 0;
	if(arr[i]==0) 
		i++;

	// convert result values to ascii 
	// also start copy from index i to the begining of arr
	int resIndex = 0;
	while(i < len)
		arr[resIndex++] = arr[i++]+'0';
	arr[resIndex]='\0';

	return arr;
}

int
main(int argc, char**argv)
{
	if (argc!=ALLOWED_ARGS_NUM) { 
		printf ("Please enter two positive integer values for multiplication.\nApp terminated. \n");
		return 1;
	}
	char* result = multiply(argv[1], argv[2]);
	if (!result)
		return 1;

	printf("%s\n", result);
	if (*result !='0')
		free(result);

	return 0;
}
