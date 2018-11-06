#include <iostream>
#include <string>
using namespace std;

/*String revers with tmp variable
input str: "Hello World!"
in result you should get 
"!dlroW olleH"
*/

void revStr (char* inputStr) {
    int size;
    char* tmpStr = inputStr;
    while (*tmpStr++ != '\0') {
        size++;
    }
    
    char tmp;
    for (int i = 0; i<size/2; i++) {
        tmp = inputStr[i];
        inputStr[i] = inputStr[size-i-1];
        inputStr[size-i-1] = tmp;
    }
}

int main() {
    char testStr[] = "Hello World!";
    revStr(testStr);
    cout << testStr << endl;
	return 0;
}



