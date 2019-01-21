#include <iostream>
#include <string>
#include <functional>
#include <vector>
using namespace std;

/*Current example display "How works lambda functions"
	1. lambda function call and compare with std::function call
	2. how to call and pass value to lambda function
	3. return value for lambda functions
*/


void printBetween(int a)
{
	if (10 < a && a < 40) {
		cout << "printBetween " << a << endl;
	}
}

void printEven (int a)
{
	if (a % 2 == 0) {
		cout << "printEven " << a << endl;
	}
}

void doWork(vector<int> &v, function<void(int)> f){
	for (auto elem : v) {
		f(elem);
	}
}

int main() {
	vector<int> v = {1,2};
	
	// test code for assigning lambda function to object std::function.
	function <void(int)> f = [](int a) {
		cout << "lambda function was called from std::function " << a << endl;
	};
	doWork(v, f);
	
	// test code to call lambda function directly without std::function
	doWork(v, [](int a) {
		cout << "lambda function was called directly " << a << endl;
	});
	
	// displaying how to use variables outisde of lambda but inside lambda code
	int varOutsideOfLambda = 1234;
	[] (int a) {
		// cout << "print variable varOutsideOfLambda " << varOutsideOfLambda << endl;  // error because of varOutsideOfLambda declaration outside of lambda
	};
	
	// if you wand to use varOutsideOfLambda value in lambda use next syntaxys inside [] :
	doWork(v, [&varOutsideOfLambda] (int a) {
		cout << "print variable varOutsideOfLambda " << varOutsideOfLambda << endl;
	});
	
	// also you can use keyword auto in next way for lambda functions:
	auto autoF = [&varOutsideOfLambda]() {
		varOutsideOfLambda = 777;
		cout << "print variable varOutsideOfLambda from var autoF with type auto " << varOutsideOfLambda << endl;
		
		return 5; // in this case lambda function will return int
		//return 5.5 // in this case lambda function will return double
	};
	auto retFromLambda = autoF();
		
	return 0;
}



