#include <stdio.h>
#include <string.h>

void strcopy (char* dest, const char* src)
{
	while ((*dest++ = *src++) != '\0');
}

int main (int argc, char** argv)
{
	char* testStrSrc = "test string copy";
	char strDest[100] = {0};
	
	strcopy (strDest, testStrSrc);
	printf("Print result: %s ", strDest);
	
	return 0;
}
