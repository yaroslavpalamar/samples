#include <iostream>
#include <queue>
using namespace std;

//void printPQ(priority_queue <int> pq)  // max priority queue
void printPQ(priority_queue<int, std::vector<int>, std::greater<int> > pq)
{
	priority_queue<int, std::vector<int>, std::greater<int> > tmpPQ = pq;
	//priority_queue <int> tmpPQ = pq;   // max priority queue
	while (!tmpPQ.empty()) {
		cout << ' ' << tmpPQ.top();
		tmpPQ.pop();
	}
	cout << '\n';
}

int 
main (int argc, char**argv)
{
	priority_queue<int, std::vector<int>, std::greater<int> > pq;
	//priority_queue <int> pq; // max priority queue
	pq.push(11);
	pq.push(45);
	pq.push(33);
	pq.push(9);
	pq.push(7);

	cout << "PQ print: " << endl;
	printPQ(pq);
	cout << "PQ size: " << pq.size() << endl;
	return 0;
}
