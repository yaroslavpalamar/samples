#include <iostream>

using namespace std;

// bst and balanced bst have time complexity m*log n, 
// trie can have O(M) but need more space.
/*
	1. Create struct TrieNode {struct TrieNode *children[ALPHABET_SIZE]; bool isEndOfWord}
	2. const int ALPHABET_SIZE=26
	3. TrieNode *getNode(void) return new trie node
		pNode = newTrieNode; pNode->isEndOfWord = false;
		init all children to 0 for(int i =0; i < ALPHABET_SIZE; i++) children[i]NULL
		retrun p pNode;
	4. void insert(struct TrieNode *root, string key)
		for (int i = 0; i < key.length(); i++) { 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode();
		pCrawl = pCrawl->children[index]; }
		set isEndOfWord=true;
	5. search()
		struct TrieNode *pCrawl = root; 
		for (int i = 0; i < key.length(); i++) { 
			int index = key[i] - 'a'; 
			if (!pCrawl->children[index]) 
				return false;
			pCrawl = pCrawl->children[index]; 
		} 
		return (pCrawl != NULL && pCrawl->isEndOfWord);	
	6. remove()
	7. isEmpty()
*/

const int ALPHABET_SIZE = 26; 
  
// trie node 
struct TrieNode 
{ 
	struct TrieNode *children[ALPHABET_SIZE]; 
  
	// isEndOfWord is true if the node represents end of a word 
	bool isEndOfWord; 
}; 
  
// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
	struct TrieNode *pNode =  new TrieNode; 
	pNode->isEndOfWord = false; 
  
	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->children[i] = NULL; 
  
	return pNode; 
} 
  
// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 
  
	for (int i = 0; i < key.length(); i++) { 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode();
		pCrawl = pCrawl->children[index]; 
	} 
  
	// mark last node as leaf 
	pCrawl->isEndOfWord = true; 
} 
  
bool search(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 
  
	for (int i = 0; i < key.length(); i++) { 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			return false;
		pCrawl = pCrawl->children[index]; 
	} 
	return (pCrawl != NULL && pCrawl->isEndOfWord); 
}

// Returns true if root has no children, else false 
bool isEmpty(TrieNode* root) 
{ 
	for (int i = 0; i < ALPHABET_SIZE; i++) 
		if (root->children[i]) 
			return false; 
	return true; 
} 
  
// Recursive function to delete a key from given Trie 
TrieNode* remove(TrieNode* root, string key, int depth = 0) 
{ 
	if (!root) 
		return NULL; 
  
	// If last character of key is being processed 
	if (depth == key.size()) { 
  
        	// This node is no more end of word after  removal of given key 
		if (root->isEndOfWord) 
			root->isEndOfWord = false; 
  
		// If given is not prefix of any other word 
		if (isEmpty(root)) { 
			delete (root); 
			root = NULL; 
		} 
  
		return root; 
	} 
  
	// If not last character, recur for the child 
	// obtained using ASCII value 
	int index = key[depth] - 'a'; 
	root->children[index] = remove(root->children[index], key, depth + 1); 
  
	// If root does not have any child (its only child got  
	// deleted), and it is not end of another word. 
	if (isEmpty(root) && root->isEndOfWord == false) { 
		delete (root); 
		root = NULL; 
	} 
  
	return root; 
}

int main() 
{ 
	// Input keys (only 'a' through 'z' in lower case) 
	string keys[] = {"go", "went", "gone", 
                    "file", "float", "grey", 
                     "history", "then" }; 
	int n = sizeof(keys)/sizeof(keys[0]); 
  
	struct TrieNode *root = getNode(); 
  
	for (int i = 0; i < n; i++) 
		insert(root, keys[i]); 
  
	search(root, "grey")? cout << "Yes\n" : cout << "No\n"; 
	search(root, "movie")? cout << "Yes\n" : cout << "No\n"; 
	
	remove(root, "grey");
	search(root, "grey")? cout << "Yes\n" : cout << "No\n";
	return 0; 
}


