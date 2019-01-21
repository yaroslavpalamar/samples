#include <iostream>
#include <string>
using namespace std;

/*Benefits from usage function pointer:
	1. You can call different functions with similar declaration and no needs to use flags.
		For example you can have one logic in function showInfo() but showInfo() will call
		any DataFromBD() or DataFromWebServer() depends on the parameters.
*/

string getDataFromBD()
{
	return "Data From BD";
}

string getDataFromWebServer()
{
	return "Data From WebServer";
}

string getDataFromServer2()
{
	return "Data From Server2";
}

void showInfo (string (*printData)()) 
{
	cout << (*printData)() << endl;
}

int main() {
	showInfo(getDataFromWebServer);
	showInfo(getDataFromServer2);
	showInfo(getDataFromBD);
	return 0;
}



