#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void memCpy(void* dest, const void *src, const size_t n)
{
	char *cSrc = (char *) src;
	char *cDest = (char *) dest;

	// Copy contents of src[] to dest[]
	for (int i = 0; i < n; i++)
		cDest[i] = cSrc[i];
}

//memmove used just when data overlaps and corrupt buffer 
//so for memmove need to use tmp buffer
void memMove(void* dest, const void *src, const size_t n)
{
	char *cSrc = (char *) src;
	char *cDest = (char *) dest;

	// Create temp arr
	char *tmp = (char*) malloc(n);
	for (int i = 0; i < n; i++)
		tmp[i] = cSrc[i];
	for (int i = 0; i < n; i++)
		cDest[i] = tmp[i];
	free(tmp);
}


int main (int argc, char** argv)
{
	char cSrc[] = "Test string"; 
	char cDest[100]; 
	memCpy(cDest, cSrc, strlen(cSrc)+1); 
	printf("Copied string is %s", cDest); 
  
	int iSrc[] = {10, 20, 30, 40, 50}; 
	int n = sizeof(iSrc)/sizeof(iSrc[0]); 
	int iDest[n], i; 
	memCpy(iDest, iSrc,  sizeof(iSrc)); 
	printf("\nCopied array is "); 
	for (i=0; i<n; i++) 
		printf("%d ", iDest[i]);

	char mSrc[] = "TestMove";
	memMove(mSrc+4, mSrc,  strlen(mSrc)+1);
	//memCpy(mSrc+4, mSrc,  strlen(mSrc)+1);
	//memmove(mSrc+4, mSrc,  strlen(mSrc)+1);
	printf("\nMoved array is %s", mSrc);
	return 0;
}


