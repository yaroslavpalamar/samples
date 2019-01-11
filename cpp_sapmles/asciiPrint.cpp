#include <iostream>
using namespace std;

/*
 * 1. first 128 symbols is constant other depends on locale
 */

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "uk");
	for (int i=0; i <= 255; i++) {
		cout << "code = " << i << "\tchar = " << (char)i << endl;
	}
	
	return 0;
}
