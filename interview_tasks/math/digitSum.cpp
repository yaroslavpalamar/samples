#include <iostream>

/*
	1. Calculate sum of every symbol inside input value.
	2. If value is negative just ignore it.
	3. input value can be between -2^63 < input < 2^63 can be type long long
 */

int digit_sum(long long number) {
	int result = 0;
	if (number<0)
		number*=-1;
	while (number !=0) {
		result += number%10;
		number /= 10;
	}
	return result;
}

int main() {
	std::cout<< digit_sum(123) << std::endl;
	std::cout<< digit_sum(-456) << std::endl;
	return 0;
}
