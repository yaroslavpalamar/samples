#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*Current example display how to sort valuse with predicate
	1. usage of sort(v.begin(), v.end(), compareValues); function from <algorithm>
	2. don't forget about lambda
*/

//example of unary predicate as function
bool greaterThenZero(int a) {
	return a > 0;
}

//example binary predicate as function
bool compareValues(int a, int b) {
	return a > b;
}

class GreaterPersonLevel {
public:
	GreaterPersonLevel (string name, int level) {
		this->name=name;
		this->level=level;
	}
	
	// predicate as functor
	bool operator ()(const GreaterPersonLevel &p, const GreaterPersonLevel &b) {
		return p.level < b.level;
	}
	
	bool operator < (const GreaterPersonLevel &a) {
		return this->level < a.level;
	}
	
//private:
	string name;
	int level;
};

int main() {
	vector<int> v = {1,2,44,55,456,3,3,4,-82,-5,-77};
	
	// display data in the vector 
	cout << "print draft vector elements" << endl;
	for (auto elem : v) {
		cout << elem << endl;
	}
	
	// display after call sort() function, by default sort() function print from less value to bigger
	cout << "print sorted vector elements, by default sort() function print from less value to bigger" << endl;
	sort(v.begin(), v.end());
	for (auto elem : v) {
		cout << elem << endl;
	}
	
	// if you want to sort elements from bigger to small then you need to use predicate as third element for function sort()
	cout << "print sorted vector elements, from bigger to smallest value" << endl;
	sort(v.begin(), v.end(), compareValues);
	for (auto elem : v) {
		cout << elem << endl;
	}
	
	// it will be better to use lambda function instead of general function for such cases
	cout << "print sorted vector elements, from bigger to smallest value with lambda function usage" << endl;
	sort(v.begin(), v.end(), [](int a, int b) 
	{
		return a>b;
	});
	for (auto elem : v) {
		cout << elem << endl;
	}
	
	vector<GreaterPersonLevel> gamers 
	{
		GreaterPersonLevel("Ann",1), 
		GreaterPersonLevel("John",5), 
		GreaterPersonLevel("Bill",4),
		GreaterPersonLevel("Bill",62),
		GreaterPersonLevel("Bill",54)
	};
	
	// print all gamers in vector
	cout << "print all gamers in vector" << endl;
	for (auto elem : gamers) {
		cout << elem.name << ", " << elem.level << endl;
	}
	
	// for calling method sort need to overload operator < for GreaterPersonLevel class
	sort(gamers.begin(), gamers.end());
	cout << "print all gamers in vector sorted from less to greater (with overloaded operator < )" << endl;
	for (auto elem : gamers) {
		cout << elem.name << ", " << elem.level << endl;
	}
	
	// you can call method sort with predicate
	sort(gamers.begin(), gamers.end(), gamers.front());
	cout << "print all gamers in vector sorted from less to greater" << endl;
	for (auto elem : gamers) {
		cout << elem.name << ", " << elem.level << endl;
	}
	
	return 0;
}



