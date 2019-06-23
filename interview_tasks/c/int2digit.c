#include <stdio.h>

void int_to_bin(int num) {
	char str[9] = {0};
	int i;
	for (i=7; i>=0; i--) {
		str[i] = (num&1)?'1':'0';
		num >>= 1;
	}
	printf("%s\n", str);
}

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
	
	printf("Also print int to bin sample: ");	
	int_to_bin(6);
	return 0;
}
