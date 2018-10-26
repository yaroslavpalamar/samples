#include <iostream>
#include <list>

using namespace std;

/*
 *
 * Implementing hash table with separate chaining
 *
 */


class HashChain {
	int container;
	
	// array with indexes to the lists(chains)
	list<int> *table;
public:
	HashChain(int Vert);
	void insertItem(int x);
	void delItem(int key);
	int hashFunct(int x) {
		return (x % container);
	}
	void printHash();
};

HashChain::HashChain(int data)
{
	this->container = data;
	table = new list<int>[container];
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

void HashChain::printHash()
{
	for (int i = 0; i < container; ++i) {
		cout << i;
		for (auto x : table [i]) {
			cout << " -> " <<x;
		}
		cout << endl;
	}
}

int
main (int argc, char** argv)
{


	return 0;
}
