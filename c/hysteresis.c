#include <stdio.h>

unsigned int hysteresis( const unsigned int inputLevel ) {
  const float margin = 1.7;
  const unsigned int numberOfLevelsOutput = 4;  // 0..4
  const unsigned int endPointInput[ numberOfLevelsOutput + 1 ] = { 0, 12, 37, 62, 87 };

  static unsigned int currentOutputLevel = 0;

  // get lower and upper bounds for currentOutputLevel
  float lb = endPointInput[currentOutputLevel] ;
  if (currentOutputLevel > 0)
	  lb -= margin;

  float ub = endPointInput[currentOutputLevel + 1];
  if (currentOutputLevel < numberOfLevelsOutput)
	  ub +=  margin;

  if ( inputLevel < lb || inputLevel > ub ) {
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
	printf("%d\n", hysteresis(99));

	return 0;
}

