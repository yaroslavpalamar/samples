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
	// hash map maximum size
	int hashTableMaxSize;
	// hash map actual size
	int actualSize;
	HashNode<K,V> **arr;
	HashNode<K,V> *dummy;
public:
	explicit HashMap(int hashTableMaxSize) 
	{ 
        	this->hashTableMaxSize = hashTableMaxSize; 
		actualSize=0; 
		arr = new HashNode<K,V>*[hashTableMaxSize]; 
          
		for(int i=0 ; i < hashTableMaxSize ; i++) 
			arr[i] = NULL; 
          
		dummy = new HashNode<K,V>(-1, -1); 
	}
	
	HashMap<K,V>& operator = (const HashMap<K,V>& other) 
	{
		//delete previous objects
		delete this->dummy;
		this->dummy=NULL;
		for (int i=0; i < hashTableMaxSize; ++i ) {
			if (this->arr[i]!=NULL && this->arr[i]->key!=-1)
				delete this->arr[i];
		}
		this->actualSize=other.actualSize;
		this->hashTableMaxSize=other.hashTableMaxSize;
		delete [] this->arr;
		// create new array with save of source obj
                this->arr = new HashNode<K,V>*[this->hashTableMaxSize];
		this->dummy = new HashNode<K,V>(-1,-1);
                for (int i=0; i <other.hashTableMaxSize; ++i ) {
			this->arr[i]=NULL;
                        if (other.arr[i]!=NULL && other.arr[i]->key!=-1) {
				HashNode<K,V> *temp = new HashNode<K,V>(other.arr[i]->key, other.arr[i]->value);
				this->arr[i]=temp;
                        }
                }
		return *this;
	}

	~HashMap()
	{
		cout << "destructor" << endl; 
		for(int i=0 ; i < hashTableMaxSize ; i++) {
			if (arr[i]!=NULL&&arr[i]->key!=-1)
				delete arr[i];
		}
		delete dummy;
		delete [] arr;
	}

	HashMap(const HashMap &other) {
		this->actualSize=other.actualSize;
		this->hashTableMaxSize=other.hashTableMaxSize;
		this->dummy = new HashNode<K,V>(-1, -1);
		this->arr= new HashNode<K,V>*[other.hashTableMaxSize];
		for (int i=0; i <other.hashTableMaxSize; ++i ) {
			if (other.arr[i]!=NULL && other.arr[i]->key!=-1) {
                                HashNode<K,V> *temp = new HashNode<K,V>(other.arr[i]->key, other.arr[i]->value);
                                this->arr[i]=temp;
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
		//if (actualSize >= hashTableMaxSize/2)
			//resize(2*hashTableMaxSize);
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
				actualSize--; 
				return temp->value; 
			}
			hashIndex++; 
			hashIndex %= hashTableMaxSize; 
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
			int counter =0; 
			if(counter++>hashTableMaxSize)  //to avoid infinite loop 
				return -1;         
			//if node found return its value 
			if(arr[hashIndex]->key == key) 
				return arr[hashIndex]->value; 
			hashIndex++; 
			hashIndex %= hashTableMaxSize; 
		}
		return -1;
	}
      
	int sizeofMap() 
	{
		return actualSize;
	}
      
	bool isEmpty() 
	{
		return actualSize == 0; 
	} 
	
	void resize (int newMaxTableSize) {
		HashNode<int,int> *tmp[newMaxTableSize];
		for (int i = 0; i < hashTableMaxSize; ++i) {
			if (arr[i]!=NULL && arr[i]->key!=-1) {
				//tmp[i] = new HashNode<int,int>(arr[i]->key, arr[i]->value);
				//delete arr[i];
			}
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
	HashMap<int, int> copyTest(6);

	HashMap<int, int> operatorTest(5); 
	copyTest = operatorTest;
	HashMap<int, int> h = copyTest;
	
	h.insertNode(1,1);
	h.insertNode(2,2); 
	h.insertNode(7,7);
	h.insertNode(2,5);
	h.insertNode(4,4); 
	h.printHashMapData();
	
	cout << h.sizeofMap() <<endl; 
	cout << h.deleteNode(2) << endl; 
	cout << h.sizeofMap() <<endl; 
	cout << h.isEmpty() << endl; 
	cout << h.get(2);
	
	cout << "print after deletion:" << endl;
	h.printHashMapData();
	return 0;
}

