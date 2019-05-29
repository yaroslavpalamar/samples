#include <stdio.h>

// check big or little endian
int checkIfLittleEndian (void)
{
	int val = 1;
	char* result = (char*)&val;
	return (int)*result;
}

int main()
{
	printf("Is it little endian? (1-true, 0-false) %d \n", checkIfLittleEndian());
	return 0;
}
