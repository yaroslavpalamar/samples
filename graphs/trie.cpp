#include <iostream>

using namespace std;

// bst and balanced bst have time complexity m*log n, 
// trie can have O(M) but need more space.

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
	return 0; 
}


