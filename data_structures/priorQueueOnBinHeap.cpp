#include <iostream>
#include <queue>
#include <climits>

using namespace std;

void swap(int *x, int *y) 
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

class MinHeap
{
	int *hArr;  // point to arr elem in heap
	int maxHSize;  // max
	int heapSize;  // current number of elements in heap
	MinHeap (const MinHeap& other) = delete;
	MinHeap& operator = (const MinHeap& other) = delete;

	// get parent index
	int parent(int i)
	{
		return (i-1)/2;	
	}
	// to get index of left child of node at index i
	int left(int i)
	{
		return (2*i + 1);
	}
	// to get index of right child of node at index i
	int right(int i)
	{
		return (2*i + 2);
	}

	// heapify mean create heap
	void heapify(int i, int hSize)
	{
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if (l < hSize && hArr[l] < hArr[i])
			smallest = l;
		if (r < hSize && hArr[r] < hArr[smallest])
			smallest = r;
		if (smallest != i) {
			swap(&hArr[i], &hArr[smallest]);
			heapify(smallest, hSize);
		}
	}
public:
	explicit MinHeap (int size) 
	{
		heapSize = 0;
		maxHSize = size;
		hArr = new int[size];
	}
	~MinHeap ()
	{
		delete [] hArr;
	}
	void printHeap()
	{
		for (int i = 0; i < heapSize; ++i) {
			cout << hArr[i] << " " ;
		}
		cout << endl;
	}
	int size ()
	{
		return heapSize;
	}
	void push(int k)
	{
		if (heapSize == maxHSize) {
			cout << "\nOverflow: Could not insert Key";
			return;
		}
		
		heapSize++;
		int i = heapSize - 1;
		hArr[i] = k;

		// Fix the min heap property if it is violated
		while (i != 0 && hArr[parent(i)] > hArr[i]) {
			swap(&hArr[i], &hArr[parent(i)]);
			i = parent(i);
		}
	}
	
	void decreaseKey(int i, int newVal)
	{
		hArr[i] = newVal;
		while (i != 0 && hArr[parent(i)] > hArr[i])
		{
			swap(&hArr[i], &hArr[parent(i)]);
			i = parent(i);
		}
	}
		
	int pop()
	{
		if (heapSize <=0)
			return INT_MAX;
		if (heapSize == 1) {
			heapSize--;
			return hArr[0];
		}
		

		// Store the min val and remove it from heap
		int root = hArr[0];
		hArr[0] = hArr[heapSize - 1];
		heapSize--;
		heapify(0, heapSize);
		return root;
	}
	
	void deleteKey(int i)
	{
		decreaseKey(i, INT_MIN);
		pop();
	}
	
	// Returns the minimum key (key at root) from min heap 
	int top() 
	{ 
		return hArr[0]; 
	}

	// main function to do heap sort 
	void heapSort() 
	{ 
  
		// One by one extract an element from heap 
		for (int i = heapSize - 1; i >= 0; i--) { 
			// Move current root to end 
			swap(hArr[0], hArr[i]); 
			// call max heapify on the reduced heap 
			heapify(0,i); 
		}
	}

};

//void printPQ(priority_queue <int> pq)  // max priority queue
void printPQ(const priority_queue<int, std::vector<int>, std::greater<int> >& pq)
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
	pq.push(200);
	pq.push(49);
	pq.push(9);
	pq.push(7);
	pq.push(20);
	//pq.top();
	//pq.pop();

	cout << "PQ print: " << endl;
	printPQ(pq);
	cout << "PQ size: " << pq.size() << endl;


	cout << "Min Heap implementation:" << endl;
	MinHeap h(11);
	h.push(10000);
	h.deleteKey(1);
	h.push(10000);
	cout << "Heap size: " << h.size() << endl;
	cout << "Print popped value: " << h.pop() << endl;
	cout << "Heap size: " << h.size() << endl;
        cout << h.top() << endl;	
	
	h.push(11);
	h.push(45);
	h.push(33);
	h.push(200);
	h.push(49);
	h.push(9);
	h.push(7);
	h.push(20);


	cout << "Heap size: " << h.size() << endl;	
	cout << "Print Heap: " << endl;
	h.printHeap();

	cout << "Decr Key: 3,2" << endl;
	h.decreaseKey(3,2);
	cout << "Print min after decrease: " << h.top() << endl;
	
	cout << "Sort Heap" << endl;
	h.heapSort();
	cout << "Print sorted Heap: " << endl;
	h.printHeap();
	return 0;
}

