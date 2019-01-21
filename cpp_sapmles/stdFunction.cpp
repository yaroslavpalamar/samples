#include <iostream>
#include <string>
#include <functional>
#include <vector>
using namespace std;

/*Current example display "How works std::function" and what benefits of using std::function.
	1. works like lambda but with std::function easier to understand lambda
*/

void getDataFromBD()
{
	cout << "Data From BD" << endl;
}

void getDataFromWeb()
{
	cout << "Data From Web" << endl;
}

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

void doWorkWithPrintEven(vector<int> &v){
	for (auto elem : v) {
		printEven(elem);
	}
}
void doWorkWithPrintBetween(vector<int> &v){
	for (auto elem : v) {
		printBetween(elem);
	}
}

void doWork(vector<int> &v, function<void(int)> f){
	for (auto elem : v) {
		f(elem);
	}
}

void doWorkCollection(vector<int> &v, vector<function<void(int)>> funcVector){
	for (auto elem : v) {
		for (auto fElem : funcVector) {
			fElem(elem);
		}
	}
}
	



void showInfo (void (*printData)()) 
{
	(*printData)();
}



int main() {
	// just for example print from function with function pointer
	showInfo(getDataFromBD);
	
	// create object from std::function similar to function pointer above we can assing function to object f.
	function<void()> f = getDataFromBD;
	f();
	f = getDataFromWeb;
	f();
	
	// Check function doWorkWithPrintEven() printEven() and doWorkWithPrintBetween() printBetween() how they work. 
	vector<int> v = {11,121,60,80,22,45,77,3,4,5,6};
	cout << "output from  doWorkWithPrintEven(v);" << endl;
	doWorkWithPrintEven(v);
	cout << "output from  doWorkWithPrintBetween(v);" << endl;
	doWorkWithPrintBetween(v);
	
	// in current example doWorkWithPrintEven() function work just with PrintEven() function, 
	// similar situation with printBetween(). The good point to unite doWorkWithprintEven(v); and doWorkWithPrintBetween(v); in one function.
	// the solution is to use std::function
	cout << "output from  doWork(v, doWorkF) where doWorkF equal to printBetween" << endl;
	function<void(int)> doWorkF = printBetween;
	doWork(v, doWorkF);
	
	// In case if function doWork() should call for example two function printBetween() 
	// and printEven() one by one need to pass to function doWork collection
	// for example like in function doWorkCollection
	vector<function<void(int)>> funcVector;
	funcVector.emplace_back(printEven);
	funcVector.emplace_back(printBetween);
	cout << "output from  doWorkCollection(vector<int> &v, vector<function<void(int)>> funcVector)" << endl;
	doWorkCollection(v, funcVector);


	return 0;
}



