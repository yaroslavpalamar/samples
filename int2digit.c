#include <stdio.h>

int
main(int argc, char** argv)
{
	const int TST_VAL=128575950;
	printf( "print digit by digit next val: %d\n", TST_VAL);
	
	int tmp=TST_VAL;
	while (tmp!=0) {
		printf ("%d\n", tmp%10);
		tmp/=10;
	}
	return 0;
}
