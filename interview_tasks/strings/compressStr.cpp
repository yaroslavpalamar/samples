#include <iostream>
using namespace std;

// example aabbcdeee->a2b2c1d1e3
string compressStr(string str)
{
	string result;
	int size = str.length();
	for (int i = 0; i < size; i++) {
		int cnt = 1;
		while (str[i] == str[i+1]){
			cnt++;
			i++;
		}
		result+=str[i];
		result+=to_string(cnt);
	}
	return result;
}

int main (int argc, char** argv)
{
	//string str = "aabbcdeee";
	//string str = "a";
	string str;
	cout << compressStr(str) << endl;
	return 0;
}
