#include <iostream>
#include <bitset>
using namespace std;

/*
 * 1. literal is constant value not variable
 * 2. std::bitset or "0b" prefix for binary representation or use conversion function.
 * 3. intToBin() input int value and pointer to bool array, return length of bits in bin form
 * 4. intToBin() impl:
 * 	 Inside while(iVal>0) cycle: 
 * 	 	1) divide by module and save the reminder to array 
 * 	 	2) divide input val by 2
 * 	 	3) return size of cycle iteration
 * 5. BinToInt() impl:
 * 		1. init variables (base=1, lastVal, Result: decVal)
 * 		2. while(bVal) calc lastVal by dividing by module 10
 * 		3. sum decVal with decVal + lastVal*base 
 * 		4. calc base = base*2. (example 1000=0*1+0*2+0*4+1*8;)
 * 		5. return decVal.
 * 		
 */

int intToBin(int iVal, bool* binArr)
{
	int i = 0;
	while (iVal>0) {
		binArr[i] = iVal % 2;
		iVal = iVal >> 1; //n = n / 2;
		i++;
	}
	return i-1;
}

int binToInt(int bVal)
{
	int base = 1;
	int decVal = 0;
	int lastVal;
	while (bVal) {
		lastVal = bVal % 10;
		decVal = decVal + lastVal*base;
		base = base*2;
		bVal /= 10;
	}
	return decVal;
}

int main (int argc, char** argv)
{
	const char A = -58;
	std::bitset<8> x(A);
	std::cout << "print char " << (int)A << ": " << x<< endl;

	const short C = -315;
	std::bitset<16> y(C);
	std::cout << "print short "<< (int)C << ": " << y << endl;

	const int BIN_LIT = 0b101010101;
	cout << "Binary literal example for 0b101010101: " << BIN_LIT << endl;
	

	bool* binArr = new bool [1000];
	const int VAL_TO_CONVERT = 1023;
	int i = intToBin(VAL_TO_CONVERT, binArr);

	cout << "Convert to binary form 1023:"<< endl;
	while (i >= 0){
		cout << binArr[i--];
	}
	
	cout <<endl;
	
	cout << "Bin To Int test: " << binToInt(111) << endl;
	return 0;
}
