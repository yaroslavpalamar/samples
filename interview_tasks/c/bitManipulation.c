#include <stdio.h>

/*
	check if even integer or odd
*/

int evenOrOdd(int val)
{
	if (val & 1)
		return 1;
	else 
		return 0;
}

/*
1         00000001    (same as 1<<0)
1<<1      00000010
1<<2      00000100
1<<3      00001000
1<<4      00010000
1<<5      00100000
1<<6      01000000
1<<7      10000000
*/
int checkNbit(int val, int n)
{
	if (val & (1 << n))
		return 1;
	else 
		return 0;
}

void setBit(int* val, int bitN)
{
	*val = *val | (1 << bitN);
}

/*
~1        11111110  (same as ~(1<<0))
~(1<<1)   11111101
~(1<<2)   11111011
~(1<<3)   11110111
~(1<<4)   11101111
~(1<<5)   11011111
~(1<<6)   10111111
~(1<<7)   01111111
*/

void unsetBit(int* val, int bitN)
{
	*val = *val & ~(1 << bitN);
}

void toggleBit(int* val, int bitN)
{
	*val = *val  ^ (1 << bitN);
}

// 1.  right propagate rightmost 1 bit: y = x | (x-1)
// 2.  isolate rightmost 1 bit: y = x | (x-1)
//    10111100  (x)
//  & 01000100  (-x)
//    --------
//    00000100
//
//    01110000  (x)
//  & 10010000  (-x)
//    --------
//    00010000
// 3. unset rightmost 1 bit:  y = x & (x-1)
// 4. turn on the rightmost 1 bit y = x | (x+1) 

/* 5. isolate rightmost 0 bit y = ~x & (x+1) 
    10111100  (x)
    --------
    01000011  (~x)
&   10111101  (x+1)
    --------
    00000001

    01110111  (x)
    --------
    10001000  (~x)
&   01111000  (x+1)
    --------
    00001000

    00000001  (x)
    --------
    11111110  (~x)
&   00000010  (x+1)
    --------
    00000010
*/

int main ()
{
	const int EVEN_VAL = 4;
	if (!evenOrOdd(EVEN_VAL))
		printf ("val %d is even \n", EVEN_VAL);
	
	const int ODD_VAL= 5;
	if (evenOrOdd(ODD_VAL))
		printf ("val %d is odd \n", ODD_VAL);

	if (checkNbit(EVEN_VAL, 2))
		printf ("bit 2 in digit %d is set \n", EVEN_VAL);
	
	if (!checkNbit(ODD_VAL, 1))
		printf ("bit 1 in digit %d is not set \n", ODD_VAL);
	const int MINUS_VAL = -33;
	if (!checkNbit(MINUS_VAL, 5))
		printf ("bit 5 in digit %d is not set because bit manipul result is 0 \n", MINUS_VAL );
	
	int val = 4;
	setBit(&val, 1);
	printf("after bit set value is %d \n", val);

	int val2 = 127;
	unsetBit(&val2, 2);
	printf("after bit unset value is %d \n", val2);

	toggleBit(&val2, 2);
	printf("after bit toggling value is %d \n", val2);


	return 0;
}
