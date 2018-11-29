#include <iostream>
#include <list>

using namespace std;

/*
 *
 * Implementing hash table with separate chaining
 *
 */


class HashChain {
	int hashTablSize;
	
	// array with indexes to the lists(chains)
	list<int> *table;

	HashChain(const HashChain& other) = delete;
	HashChain& operator = (const HashChain& other) = delete;
public:
	explicit HashChain(int Vert);
	void insertItem(int x);
	void delItem(int key);
	int hashFunct(int x) {
		return (x % hashTablSize);
	}
	void printHash();
	bool isItemInTable (int val);
};

HashChain::HashChain(int data)
{
	this->hashTablSize = data;
	table = new list<int>[hashTablSize];
}

void HashChain::insertItem(int key)
{
	int index = hashFunct(key);
	table[index].push_back(key);
}

void HashChain::delItem(int key)
{
	//get hesh id of key
	int index = hashFunct(key);

	// find the key in list
	list<int>::iterator i;
	for (i = table[index].begin(); i != table[index].end(); ++i) {
		if (*i == key) { 
			break;
		}
	}
	// if key is found remove it
	if (i != table[index].end())
		table[index].erase(i);
}

bool HashChain::isItemInTable(int val)
{
	int index = hashFunct(val);
	for (list<int>::iterator i = table[index].begin(); i !=table[index].end(); ++i) {
		if (*i==val) {
			return true;
		}
	}
	return false;
}

void HashChain::printHash()
{
	for (int i = 0; i < hashTablSize; ++i) {
		cout << i;
		for (auto x : table [i]) {
			cout << " -> " <<x;
		}
		cout << endl;
	}
	cout << endl;
}

int
main (int argc, char** argv)
{
	// array with keys
	int arr[] = {10, 14, 44, 99, 12, 19,20,3,4};

	// insert the keys to hash table
	HashChain h(7);

	for (int i : arr) {
		h.insertItem(i);
	}
	
	cout << "Print added data to the table:"<<endl;	
	h.printHash();
	
	h.delItem(4);
	h.delItem(10);
	h.delItem(10);
	

	// print after deletion
	cout << "Print table after deletion:" << endl;
	h.printHash();
	
	cout << "Print 1 if item exist in the table and 0 if not:" << endl;
	cout << "Item 99: " << h.isItemInTable(99) << endl;
	cout << "Item 4: " << h.isItemInTable(4) << endl;
	cout << "Item 12: " << h.isItemInTable(12) << endl;
	cout << "Item 12: " << h.isItemInTable(19) << endl;

	return 0;
}
