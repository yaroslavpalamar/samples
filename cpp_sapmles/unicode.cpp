#include <iostream> 
using namespace std; 
  
int main(int argc, char** argv) 
{
	wchar_t w  = L'A'; 
	cout << "Wide character val: " << w << endl ; 
	cout << "Size of the wide char: " << sizeof(w) << endl; 
    
	// wide-char type array string
	wchar_t testW[] = L"Test Unicode print has length" ; 
	wcout << testW << L": " << wcslen(testW) << endl; 
	
	return 0; 
} 

