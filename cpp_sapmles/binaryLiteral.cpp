#include <iostream>
#include <bitset>
using namespace std;

int decToBin(int n, bool* binArr)
{
	int i = 0;
	while (n>0) {
		binArr[i] = n % 2;
		n= n>>1; //n = n / 2;
		i++;
	}
	return i-1;
}

int main (int argc, char** argv)
{
	char a = -58;    
	std::bitset<8> x(a);
	std::cout << "print char -58: " << x<< endl;

	short c = -315;
	std::bitset<16> y(c);
	std::cout << "print short -352: "<< y << endl;

	int binLit = 0b101010101;
	cout << "Binary literal example for 0b101010101: " << binLit << endl;
	
	cout << "Binary literal in binary form:"<< endl;
	bool* binArr = new bool [1000];
	int i = decToBin(1023, binArr);
	while (i>=0){
		cout << binArr[i--];
	}
	cout <<endl;
	return 0;
}
