#include <iostream>
#include <set>
using namespace std;

/*
	1. doubele ended prio queue can be implemented with <set>.
	2. Create struct with private value set<int> s;
	3. all methods needed that can just use <set> methods from stl library:
		int size(), bool isEmpty(), insert(), getMin(), getMax(s.rbegin())
		void delMin(if size==0 return ) call erase(sbegin) delMax( it=s.end() erase(it))

*/

struct DblEndPrQueue {
	int size ()
	{
		return s.size();
	}

	bool isEmpty()
	{
		return (s.size() == 0);
	}

	void insert(int x)
	{
		s.insert(x);
	}

	int getMin()
	{
		return *(s.begin());
	}

	int getMax()
	{
		return *(s.rbegin());
	}

	void delMin()
	{
		if (s.size() == 0)
			return;
		s.erase(s.begin());
	}

	void delMax()
	{
		if (s.size() == 0)
			return;
		auto it = s.end();
		it--;
		s.erase(it);
	}
private:
	set<int> s;
};

int main (int argc, char** argv)
{
	DblEndPrQueue d;	
	d.insert(10);
	d.insert(50);
	d.insert(40);
	d.insert(20);
	cout << d.getMin() << endl; 
	cout << d.getMax() << endl; 
	d.delMax(); 
	cout << d.getMax() << endl; 
	d.delMin(); 
	cout << d.getMin() << endl;
	return 0;
}

