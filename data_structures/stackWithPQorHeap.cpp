#include <queue>
#include <iostream>
using namespace std;

/*
	1. Create class stack with two private member: 
		pq - priority_queue (inside pq can be pair<int,int> in case if we need to save cnt for pushed val)
		int cnt to count
	2. Also define publick methods 
		constructor Stack() init cnt=0
		push()
		pop() check if empty if empty print error
		top() retrurn pq.top().second (for pair use .second)
		isEmpty
*/

typedef pair<int, int> p;

class Stack {
	int cnt;
	priority_queue< pair<int,int> > pq;
public:
	Stack()
	{
		cnt = 0;
	}
	void push(int val) 
	{
		cnt++;
		pq.push(pair<int, int>(cnt,val));
	}
	void pop() 
	{
		if (pq.empty()) {
			cout << "Nothing to pop";
		}
		cnt--;
		pq.pop();
	}

	int top() 
	{
		p tmp=pq.top();
		return tmp.second;
	}
	bool isEmpty()
	{
		return pq.empty();
	}
};

int 
main (int argc, char** argv)
{
	cout << "push 1,2,3 to stack" << endl;
	Stack s;
	s.push(5);
	s.push(1);
	s.push(2);
	s.push(3);
	
	cout << "pop from stack:" << endl;
	while(!s.isEmpty()) {
		cout << s.top()<<endl;
		s.pop();
	}

	return 0;
}


