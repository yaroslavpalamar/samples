#include <stdio.h>

unsigned int hysteresis( const unsigned int inputLevel ) {
	const float endPointInput[] = { 0, 12.5, 37.5, 62.5, 87.5, 100};
	
	// because start count with plus or minus from 12.5 or 37.5 etc..
	// 2.49999 but not 2.5 because it will not work if upper bound or lower bound is input val.
	const float margin = 2.49999;
	const unsigned int numberOfLevelsOutput = 4;

	static unsigned int currentOutputLevel = 0;

	// get lower and upper bounds for currentOutputLevel
	float lb = endPointInput[currentOutputLevel] ;
	if (currentOutputLevel > 0)
		lb -= margin;

	float ub = endPointInput[currentOutputLevel + 1];
	if (currentOutputLevel < numberOfLevelsOutput)
		ub +=  margin;

	//printf("%f\n", lb);
	//printf("%f\n", ub);
	if (inputLevel < lb || inputLevel > ub ) {
		unsigned int i;
		for ( i = 0 ; i < numberOfLevelsOutput ; i++ ) {
			if (inputLevel >= endPointInput[i] && inputLevel <= endPointInput[i + 1])
				break;
		}
		currentOutputLevel = i;
	}
	return currentOutputLevel;
}
int main()
{
	printf("%d\n", hysteresis(5));
	printf("%d\n", hysteresis(16));
	printf("%d\n", hysteresis(11));
	printf("%d\n", hysteresis(10));
	printf("%d\n", hysteresis(100));
	printf("%d\n", hysteresis(91));
	printf("%d\n", hysteresis(86));
	printf("%d\n", hysteresis(85));
	printf("%d\n", hysteresis(10000));
	return 0;
}

