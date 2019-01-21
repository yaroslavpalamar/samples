#include <iostream>
#include <sstream>
using namespace std;

/*
	1. (2e-10*2+3=3.0000000004) (2e+5*2=400000)
	2. C++ istringstream os(s) >> double
	3. C use printf (%e)
FYI:
kibi 2^10 or 1024 bytes. or if base 10 it will be 10^3 
mebi 2^20 or 
gibi 2^30
tebi 2^40 
pebi 2^50
exbi 2^60
zebi 2^7*10
yobi 2^8*10
*/

int main(int argc, char** argv)
{
	string s("1.60000000000000000000000000000000000e+01");
	istringstream os(s);
	double d;
	os >> d;
	cout << "Scientific notation: " << endl << s << "   double representation:" << d << endl;
	
	string s1("1.60000000000000000000000000000000000e+02");
	os.clear();
	os.str(s1);
	os >> d; 
	cout << "Scientific notation: " << endl << s1 << "   double representation:" << d << endl;

	string s2("1.60000000000000000000000000000000000e-03");
	os.clear();
	os.str(s2);
	os >> d;
	cout << "Scientific notation: " << endl << s2 << "   double representation:" << d << endl;
	
	// in C
	cout << "Other examples of representation in C: " << endl;

	printf("\n Double for:%f\n sci:%e \n or \n sci:%E   \n",d,d,d);

	cout << "Values using scientific with std::scientific are : " << scientific << endl;
	cout << d << '\n';


	float var = 1.54334E-34;
	double var2 = 1.54334E-34;
	
	printf("\n normal float:%f\n sci:%e \n or \n sci:%E   \n",var,var,var);
	printf("\n normal double:%f\n sci:%e \n or \n sci:%E   \n",var2,var2* 1.0E3 ,var2 * 1.0e3);
	

	return 0;
}
