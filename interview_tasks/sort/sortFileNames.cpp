#include <iostream>
#include <vector>


using namespace std;

/*
 * 1. N image files named from 1 to N like IMG1.jpg IMG2.jpg...
 * 2. For sorted by name the order could be incorrect because of IMG1.jpg IMG10.jpg for 10 files*
 * 3. N range [1,1000000]
 * 4. if higher than 1000 return just first 1000 file names*/

void generateVal(int i, int n, vector<string>& result) {
	if (i>n || result.size() == min(n, 1000))
		return;
	result.push_back("IMG"+to_string(i)+".jpg");
	for (int j = 0; j<10; j++) {
		generateVal(i*10+j,n,result);
	}
}

void sortTheFiles(int n, vector<string>& result) {
	for (int i = 1; i<10; i++) {
		generateVal(i, n , result);
	}

}

int main() {
	vector<string>tst;
	sortTheFiles(16, tst);
	for (string str:tst)
		cout << str <<endl;
	return 0;
}
