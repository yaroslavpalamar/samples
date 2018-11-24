#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// template for print any value
template <typename T>
void print(const T& t)
{
	std::cout << t << endl;
}

template <typename T>
string retStr(const T& t)
{
	stringstream ss;
	ss << t;
	return ss.str();
}

template <typename ... Param>
vector<string> getManyAndRetStr(const Param& ... param)
{
	return {retStr(param)...};
}

int main (int argc, char** argv)
{
	print ("hello world");
	print (123);	
	cout << retStr("test")<<endl;
	cout << retStr(556)<<endl;

	// imagine that we want toconvert not one string but many strings:
	// for that use variadics
	const auto vec = getManyAndRetStr("variad", 1,2, "test", '5', 90);
	for (const auto &o : vec) {
		cout << o << '\n';
	}

	return 0;
}
