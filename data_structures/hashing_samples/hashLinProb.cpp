#include <iostream>
using namespace std;

/*
	Hash Map Linear probing:
	1. template class HashMap contain hashTableMaxSize=capacity and actualSize private variables
		template HashNode<Key, Val>**arr and pointer on dummy HashNode<K,V>
		also can be implemented private method to check if checkIfMapSizeLessThenAllowed()
	2. explicit HashMap(capacity) init variables, actualSize=0 and allocate memory for **arr and assign to NULL, also init dymmy to (-1,-1)
	3. destructor delete every element and allocated array and dummy
	4. hashCode(key) function return key%hashTableMaxSize also add function isEmpty(), maxHashMapSize(), hashMapSize()
	5. get(1. get hash 2. loop while arr[hash] not NULL 3. check for key if found return 
			4. increment hash and call hashCode(key))
	6. insertNode() {1. allocate mem for one HashNode and get hash for this node hashIndex = hashCode(key);
			 2. loop through arr(arr[hash]!=NULL&&hashKey!=arr[hash]->key&&node->key!=-1)(hashKey=hashCode(++hashKey))}
			 3. if found empty node increase hashMap size and assign node
	7. deleteNode() {1. find hash 2. loop throug arr whil not NULL and compare keys
			3. if not foud increment hash and call hashCode(hash)
			4. if found assign dummy to value to that place and decrease size of hashMap and return value
			5. if the end of the loop return -1}
	8. Aditionally may be implemented resize() function assignment operator and copy constructor.
*/

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
	// hash map maximum size
	int hashTableMaxSize;
	// hash map actual size
	int actualSize;
	HashNode<K,V> **arr;
	HashNode<K,V> *dummy;
	void checkIfMapSizeLessThenAllowed(const int& hashTableMaxSize, int& newSize) 
	{
		// if size is 1 for example then we don't have NULL pointer in the end of array
		const int MIN_ARR_MAP_SIZE = 2;
		if (hashTableMaxSize<2)
			newSize=MIN_ARR_MAP_SIZE;
		else
			newSize=hashTableMaxSize;
	}
public:
	explicit HashMap(int hashTableMaxSize) 
	{ 	
		checkIfMapSizeLessThenAllowed(hashTableMaxSize, this->hashTableMaxSize);	
		actualSize=0; 
		arr = new HashNode<K,V>*[this->hashTableMaxSize]; 
          
		for(int i=0 ; i < this->hashTableMaxSize ; i++) 
			arr[i] = NULL; 
          
		dummy = new HashNode<K,V>(-1, -1); 
	}
	
	HashMap<K,V>& operator = (const HashMap<K,V>& other) 
	{
		if (this == &other) return *this;
		//delete previous objects
		delete this->dummy;
		this->dummy=NULL;
		for (int i=0; i < hashTableMaxSize; ++i ) {
			if (this->arr[i]!=NULL && this->arr[i]->key!=-1)
				delete this->arr[i];
		}
		this->actualSize=other.actualSize;
		checkIfMapSizeLessThenAllowed(other.hashTableMaxSize, this->hashTableMaxSize);
		delete [] this->arr;
		// create new array with save of source obj
                this->arr = new HashNode<K,V>*[this->hashTableMaxSize];
		this->dummy = new HashNode<K,V>(-1,-1);
                for (int i=0; i <other.hashTableMaxSize; ++i ) {
			this->arr[i]=NULL;
                        if (other.arr[i]!=NULL && other.arr[i]->key!=-1) {
				HashNode<K,V> *temp = new HashNode<K,V>(other.arr[i]->key, other.arr[i]->value);
				this->insertNode(temp->key, temp->value);
                        }
                }
		return *this;
	}

	~HashMap()
	{
		for(int i=0 ; i < hashTableMaxSize ; i++) {
			if (arr[i]!=NULL&&arr[i]->key!=-1)
				delete arr[i];
		}
		delete dummy;
		delete [] arr;
	}

	HashMap(const HashMap &other) {
		this->actualSize=other.actualSize;
		checkIfMapSizeLessThenAllowed(other.hashTableMaxSize, this->hashTableMaxSize);
		
		this->dummy = new HashNode<K,V>(-1, -1);
		this->arr= new HashNode<K,V>*[other.hashTableMaxSize];
		for (int i=0; i <other.hashTableMaxSize; ++i ) {
			if (other.arr[i]!=NULL && other.arr[i]->key!=-1) {
                                HashNode<K,V> *temp = new HashNode<K,V>(other.arr[i]->key, other.arr[i]->value);
				this->insertNode(temp->key, temp->value);
                        }
		}
	}
	
	int hashCode(K key) 
	{ 
		return key % hashTableMaxSize; 
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
			hashIndex = hashCode(hashIndex);
		}
          
		//if new node to be inserted increase the current size 
		if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1) 
			actualSize++; 
		arr[hashIndex] = temp; 

		// double table size if 50% full
		if (actualSize >= hashTableMaxSize/2)
			resize(2*hashTableMaxSize);
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
 
				delete arr[hashIndex];

				//Insert dummy node here for further use 
				arr[hashIndex] = dummy; 
                  
				// Reduce size
				actualSize--; 
				return temp->value; 
			}
			hashIndex++; 
			hashIndex = hashCode(hashIndex);
		}
		return -1;
	}
      
	V get(int key) 
	{
		// Apply hash function to find index for given key 
		int hashIndex = hashCode(key); 
		
		//finding the node with given key    
		while(arr[hashIndex] != NULL) 
		{    
			/*int counter =0; 
			if(counter++>hashTableMaxSize)  //to avoid infinite loop 
				return -1;  */       
			//if node found return its value 
			if(arr[hashIndex]->key == key) 
				return arr[hashIndex]->value; 
			hashIndex++; 
			hashIndex = hashCode(hashIndex); 
		}
		return -1;
	}
      
	int sizeOfMap() 
	{
		return actualSize;
	}
	int hashMapMaxSize()
	{
		return hashTableMaxSize;
	}
      
	bool isEmpty() 
	{
		return actualSize == 0; 
	} 
	
	void resize (int newMaxTableSize) {
		cout << "was resized" << endl;
		// copy all data in arr to temprary tmp array
		HashNode<K,V> **tmp = new HashNode<K,V>*[hashTableMaxSize];
		for (int i=0; i <hashTableMaxSize; ++i ) {
			tmp[i]=NULL;
                        if (arr[i]!=NULL && arr[i]->key!=-1) {
                                HashNode<K,V> *temp = new HashNode<K,V>(arr[i]->key, arr[i]->value);
                                tmp[i]=temp;
                        }
                }
		
		// delete old arr
		for (int i = 0; i < hashTableMaxSize; ++i) {
			if (arr[i]!=NULL && arr[i]->key!=-1) 
				delete arr[i];
		}
		delete this->dummy;
		this->dummy=NULL;
		delete [] arr;
		
		// create new arr
		this->arr=new HashNode<K,V>*[newMaxTableSize];
		for (int i=0; i < newMaxTableSize; ++i) {
			arr[i]=NULL;
		}
		// update sizes
		this->hashTableMaxSize=newMaxTableSize;
		this->actualSize=0;
		dummy = new HashNode<K,V>(-1, -1);
		// copy from tmp arrey to new arrey
		for (int i=0; i<hashTableMaxSize/2; ++i) {
			if (tmp[i]!=NULL)
				this->insertNode(tmp[i]->key, tmp[i]->value);
		}
	}
      
	void printHashMapData() 
	{ 
		for(int i=0 ; i<hashTableMaxSize ; i++) 
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
	HashMap<int, int> copyTest(1);
	HashMap<int, int> operatorTest(1); 
	copyTest = operatorTest;
	HashMap<int, int> h = copyTest;
	
	h.insertNode(1,1);
	h.insertNode(2,2); 
	h.insertNode(7,7);
	h.insertNode(2,5);
	h.insertNode(4,4); 
	
	cout << "Print max size of Map: " << h.hashMapMaxSize() << endl;	

	h.printHashMapData();
	
	cout << "Size Of Map:" << h.sizeOfMap() <<endl; 
	cout << "Deleted node:" << h.deleteNode(2) << endl; 
	cout << "Size of Map:" << h.sizeOfMap() <<endl; 
	cout << "Check if empty map:" << h.isEmpty() << endl; 
	cout << "Get index 2:" << h.get(2) << endl;
	cout << "Get index 7:" << h.get(7) << endl;	

	cout << "\nprint after deletion:" << endl;
	h.printHashMapData();
	return 0;
}

