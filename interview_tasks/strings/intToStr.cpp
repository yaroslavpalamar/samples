#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
void
testSwap (T& a, T& b)
{
	T tmp = move(b);
	b = move(a);
	a = move(tmp);
}

void revStr(string& str) 
{
	int size = str.length();
	for (int i = 0; i < size/2; i++) {
		testSwap(str[size-i-1], str[i]);
	}
}

string intToStr(int inp) 
{
	string result;
	bool isNeg = false;
	if (inp<0) {
		isNeg=true;
		inp*=-1;
	}
	
	while (inp != 0) {
		result += to_string(inp%10);
		inp /= 10;
	}
	if (isNeg) {
		result += '-';
	}

	//reverse(result.begin(), result.end());
	revStr(result);
	
	return result;
}

int main()
{
	cout << intToStr(-533256) << endl;
	return 0;
}
