#include <iostream>
using namespace std;

template<typename K, typename V>
struct HashNode 
{
	K key;
	V value;
	HashNode(K k, V v) 
	{
		this->key = k;
		this->value = v;
	}
};

template <class K, class V>
class HashMap 
{
	int capacity;
	int size;
	HashNode<K,V> **arr;
	HashNode<K,V> *dummy;
public:
	HashMap(int capacity) 
	{ 
        	this->capacity = capacity; 
		size=0; 
		arr = new HashNode<K,V>*[capacity]; 
          
		for(int i=0 ; i < capacity ; i++) 
			arr[i] = NULL; 
          
		dummy = new HashNode<K,V>(-1, -1); 
	}
	
	int hashCode(K key) 
	{ 
		return key % capacity; 
	}


	void insertNode(K key, V value) 
	{ 
		HashNode<K,V> *temp = new HashNode<K,V>(key, value); 
          
		int hashIndex = hashCode(key); 
          
		// get free space in table
		while(arr[hashIndex] != NULL && arr[hashIndex]->key != key 
			&& arr[hashIndex]->key != -1) 
		{
			hashIndex++; 
			hashIndex %= capacity; 
		}
          
			//if new node to be inserted increase the current size 
		if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1) 
			size++; 
		arr[hashIndex] = temp; 
	} 
      
	V deleteNode(int key) 
	{
		int hashIndex = hashCode(key); 
		// finding the node with given key 
		while(arr[hashIndex] != NULL) 
		{ 
			//if node found 
			if(arr[hashIndex]->key == key) 
			{ 
				HashNode<K,V> *temp = arr[hashIndex]; 

				//Insert dummy node here for further use 
				arr[hashIndex] = dummy; 
                  
				// Reduce size
				size--; 
				return temp->value; 
			}
			hashIndex++; 
			hashIndex %= capacity; 
		}
		// if not found return null 
		return NULL; 
	}
      
	V get(int key) 
	{
		// Apply hash function to find index for given key 
		int hashIndex = hashCode(key); 
		int counter=0; 
		
		//finding the node with given key    
		while(arr[hashIndex] != NULL) 
		{    
			int counter =0; 
			if(counter++>capacity)  //to avoid infinite loop 
				return NULL;         
			//if node found return its value 
			if(arr[hashIndex]->key == key) 
				return arr[hashIndex]->value; 
			hashIndex++; 
			hashIndex %= capacity; 
		}
		// if not found return null 
		return NULL; 
	}
      
	int sizeofMap() 
	{
		return size; 
	}
      
	bool isEmpty() 
	{
		return size == 0; 
	} 
      
	void printHashMapData() 
	{ 
		for(int i=0 ; i<capacity ; i++) 
		{ 
			if (arr[i] != NULL && arr[i]->key != -1) { 
				cout << "key = " << arr[i]->key;
				cout << "  value = "<< arr[i]->value << endl;
			}
		}
	}
};

int main (int argc, char** argv) 
{
	HashMap<int, int> *h = new HashMap<int, int>(20); 
	h->insertNode(1,1); 
	h->insertNode(2,2); 
	h->insertNode(7,7);
	h->insertNode(2,5);
	h->insertNode(4,4); 
	h->printHashMapData();
	
	cout << h->sizeofMap() <<endl; 
	cout << h->deleteNode(2) << endl; 
	cout << h->sizeofMap() <<endl; 
	cout << h->isEmpty() << endl; 
	cout << h->get(2);
	
	cout << "print after deletion:" << endl;
	h->printHashMapData();
	return 0;
}

