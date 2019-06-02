#include <iostream>

/*String revers with tmp variable
input str: "Hello World!"
in result you should get 
"!dlroW olleH"
*/

void revStr (char* inputStr) {
    int size=0;
    char* tmpStr = inputStr;
    while (*tmpStr++ != '\0') {
        size++;
    }
    
    for (int i = 0; i<size/2; i++) {
        char tmp = inputStr[i];
        inputStr[i] = inputStr[size-i-1];
        inputStr[size-i-1] = tmp;
    }
}

int main() {
    char testStr[] = "Hello World!";
    revStr(testStr);
    std::cout << testStr << '\n';
	return 0;
}


