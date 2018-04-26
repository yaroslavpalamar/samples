#include <iostream>
using namespace std;

/*
Replace symbols in subsrtrings (inside words change symbol "2" with "*") like in next example:

Input string:
    a new string which contain a substrings to modify

Result:
   a ne* st*ing wh*ch co*tain a su*strings to mo*ify
*/

void replaceInWords(char* str, int replace_num, char replace_sym) 
{ 
    char* s = str; 
    char* word_begin = str; 
  
    while (*s != '\0') { 
        if (*s == ' ') { 
            word_begin = s + 1; 
        } else { 
            if (s - word_begin == replace_num) 
                *s = replace_sym; 
        } 
  
        s++; 
    } 
} 

int main() {
    char str[] = "a new string which contain a substrings to modify"; 
    replaceInWords(str, 2, '*'); 
    cout << str << endl; /*result: a ne* st*ing wh*ch co*tain a su*strings to mo*ify*/
    return 0;
}
