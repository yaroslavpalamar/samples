#include <iostream>

/*
	1. example 1331, 2772, 5, 222
	2. input value is between 0 < n <= 10,000,000,000
	3. true if n is a palindrome and false otherwise
	4. Firstly reerse the number after that compare two values if they are the same
	5. As for negative ignore minus.
 */

bool isNumericPalindrome(long long number) {
	if (number < 1)
		number *=-1;
    long long tmp = number;
    long long revNum = 0;
    while (tmp != 0) {
    	int lastNum = tmp%10;
    	revNum = revNum*10 + lastNum;
    	tmp /=10;
    }
    if (revNum == number)
    	return true;
    else
    	return false;
}

bool isNumericPalindrome2(long long number) {
	std::string num = std::to_string(number);
	int lhs = 0;
	int rhs = num.size() -1;

	while(lhs < rhs) {
		if(num[lhs] != num[rhs]) {
			return false;
		}
		lhs++;
		rhs--;
	}
	return true;
}

int main() {
	std::cout<< isNumericPalindrome2(32223) << std::endl;
	std::cout<< isNumericPalindrome2(-656) << std::endl;
	std::cout<< isNumericPalindrome2(-756) << std::endl;
	std::cout<< isNumericPalindrome2(543) << std::endl;
	std::cout<< isNumericPalindrome2(1) << std::endl;
	std::cout<< isNumericPalindrome2(99) << std::endl;
	std::cout<< isNumericPalindrome2(10000000001) << std::endl;
	return 0;
}
