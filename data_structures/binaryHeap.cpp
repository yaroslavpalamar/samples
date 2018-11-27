#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


/*
min heap example:
            11                      4  - always smallest element
         /      \               /       \
       39        200          33         70  
      /                      /  \        /  \
    40                     80    90    110   120

max heap example:
	100   - always bigest element
      /	    \
     19	     36
    / \      /  \
   17	3   25   1


Also exist Binomial and Fibonacci heaps.
*/


bool isHeap(vector<int> v1)
{
	if (is_heap(v1.begin(), v1.end()))
		cout << "The container is heap ";
	else
		cout << "The container is not heap"; 
	cout << endl;
}

void heapTest()
{
	vector<int> v1 = {10,20,30,35,25};
	isHeap(v1);
	//convert vector into a heap
	make_heap(v1.begin(), v1.end());

	cout << "The max elem of heap is: ";
	cout << v1.front() << endl;
	isHeap(v1);
}

int main (int argc, char** argv)
{
	heapTest();
	return 0;
}

