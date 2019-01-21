#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* Current example display what is predicate
	1. What is the predicate? (predicate is a functor or function which return bool value)
	2. How to check how many values in vector greater then zero? What is algorithm cout_if?
	3. Show example of predicate function and predicate functor.
*/

//predicate as function
bool greaterThenZero(int a) {
	return a > 0;
}

//predicate as function
bool lessThenZero(int a) {
	return a < 0;
}

class GreaterPersonLevel {
public:
	GreaterPersonLevel (string name, int level) {
		this->name=name;
		this->level=level;
	}
	
	// predicate as functor
	bool operator ()(const GreaterPersonLevel &p) {
		return p.level > 2;
	}
	
private:
	string name;
	int level;
};


int main() {
	cout << "is 5 greater then zero or not = " << greaterThenZero(5) << endl;
	cout << "is -1 greater then zero or not = " << greaterThenZero(-1) << endl;
	
	vector<int> v = {1,2,3,4,-82,-5,-77};
	
	int resultGreater = count_if(v.begin(), v.end(), greaterThenZero);
	cout << "in vector v we have " << resultGreater << " values greater then zero" << endl;
	// with count_if algorithm we go throug vector and run predicate lessThenZero for every element in the vector.
	int resultLess = count_if(v.begin(), v.end(), lessThenZero);
	cout << "in vector v we have " << resultLess << " values less then zero" << endl;
	
	vector<GreaterPersonLevel> gamers 
	{
		GreaterPersonLevel("Ann",1), 
		GreaterPersonLevel("John",2), 
		GreaterPersonLevel("Bill",3),
		GreaterPersonLevel("Bill",4),
		GreaterPersonLevel("Bill",5)
	};
	// with method front() we get first object from vector gamers,
	int resultPerson = count_if(gamers.begin(), gamers.end(), gamers.front());
	cout << "in vector gamers we have " << resultPerson << " values greater then level 2" << endl;
	
	return 0;
}



