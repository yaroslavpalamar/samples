#include <iostream>
#include <unordered_set>
using namespace std;

void remAsciiDupl (std::string& str) {
	unordered_set <char> repElem;
	int size = str.length();
	for (int i = 0; i < size; i++) {
		if (repElem.find(str.at(i)) != repElem.end()){
			str.erase(i,1);
			size--;
		} else 
			repElem.insert(str[i]);
	}
}

int
main()
{
	string test = "abcadca";
	remAsciiDupl(test);
	cout << test << endl;
	return 0;
}

