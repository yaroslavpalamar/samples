#include <stdio.h>
/*
Input: num1 = "123", num2 = "456"
Output: "56088"
*/


int
main(int argc, char**argv)
{
	for (int i=0; i<argc; i++) {
		printf("%s\n", argv[i]);
	}
	return 0;
}
