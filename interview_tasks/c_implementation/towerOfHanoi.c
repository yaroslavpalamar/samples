#include <stdio.h>

/*
 *	|	|	|
 *	|	|	|
 *	|	|	|
 *	A	B	C
 */

void towerOfHanoi(int n, char from_rod, char to_rod, char mid_rod)
{
	static int i=0, recCall1=0, recCall2=0, recCall3=0;
	if (n==1) {
		printf("\n %d Move disk 1 from rod %c to rod %c", ++i, from_rod, to_rod);
		printf("\n %d (recCall1)\n", ++recCall1);
		// after this return part of instraction in stack will be executed 
		// and soma disks will be moved in proper places
		return;
	}
	towerOfHanoi(n-1, from_rod, mid_rod, to_rod);
	printf("\n %d (recCall2)\n", ++recCall2);
	printf("\n %d Move disk %d from rod %c to rod %c", ++i, n, from_rod, to_rod );
	towerOfHanoi(n-1, mid_rod, to_rod, from_rod);
	printf("\n n=%d, %d (recCall3)\n", ++recCall3, n);
}

int
main(int argc, char** argv)
{
	// number of disks
	int n = 3;
	towerOfHanoi(n, 'A', 'C', 'B');
	return 0;
}

