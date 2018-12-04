#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

/*Least recently used cache algorithm. Read about dynamic memory in OS.*/

class LRUCache
{
	// store keys of cache
	list <int> queue;

	// store references of key in cache
	unordered_map<int, list<int>::iterator> uMap;
	int maxSize;

public:
	LRUCache(int);
	void referKeyToLRU(int);
	void display();
};

	LRUCache::LRUCache(int size)
	{
		maxSize = size;
	}

	// refers key x with in the LRU cache
	void LRUCache::referKeyToLRU(int x)
	{
		// cache is full
		if (uMap.find(x) == uMap.end()) {
			// cache is full
			if (queue.size() == maxSize) {
				//delete least recently used element
				int last = queue.back();
				queue.pop_back();
				uMap.erase(last);	
			}
		} else { // present in cache need to replace..
			queue.erase(uMap[x]);
		}
	
		// update reference
		queue.push_front(x);
		uMap[x] = queue.begin();
	}

	void LRUCache::display()
	{
		for (auto it = queue.begin(); it != queue.end(); it++)
			cout << (*it) << " ";
		cout << endl;
	}
	
	

int main()
{
	LRUCache c(4);
	c.referKeyToLRU(1);
	c.referKeyToLRU(2);
	c.referKeyToLRU(3);
	c.referKeyToLRU(1);
	c.referKeyToLRU(4);
	c.referKeyToLRU(5);
	c.display();
	return 0;
}

