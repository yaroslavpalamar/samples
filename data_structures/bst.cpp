#include <iostream>

/*
	1. BST can be defined as struct with two pointers (left, right) to othe nodes and value
	2. node* newNode(int val) function allocate memory, return pointer to allocated memory and assign value to allocated node 
		also assign left and right pointers to NULL 
	3. node* bstSearch(root, intsKey) if root==NULL or root->key==sKey return root 
		(if root->key > sKey return bstSearch(root->left, sKey))
		by default return bstSearch(root->right, sKey)
	4. inorder traversal void inorder (node* root). If root!=NULL call inorder recursively to left and right
	5. insert (), if root == NULL call newNode() 
		call insert left if val < val in root and else if val > val in root call insert right
*/

struct node {
	node* left;
	node* right;
	int key;
};

node* bstSearch (node *root, int sKey)
{
	if (root == NULL || (root->key == sKey))
		return root;
	
	if (root->key > sKey)
		return bstSearch(root->left, sKey);
	
	return bstSearch(root->right, sKey);
}

struct node *newNode(int item) 
{ 
	struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
}

// inorder traversal of bst
void inorder(struct node *root) 
{ 
	if (root != NULL) { 
		inorder(root->left); 
		printf("%d \n", root->key); 
		inorder(root->right); 
	} 
}

struct node* insert(struct node* node, int key) 
{ 
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key); 
  
	/* Otherwise, recur down the tree */
	if (key < node->key) 
		node->left  = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key);    
  
	/* return the (unchanged) node pointer */
	return node; 
}

int
main ()
{

/* Let us create following BST 
 *               50 
 *            /     \
 *           30      70 
 *          /  \    /  \
 *        20   40  60   80 */
	struct node *root = NULL; 
	root = insert(root, 50); 
	insert(root, 30); 
	insert(root, 20); 
	insert(root, 40); 
	insert(root, 70); 
	insert(root, 60); 
	insert(root, 80); 
	
	// print values using inorder traversal
	inorder(root);

	int val = 60;
	printf("Search for %d, result is %d\n", val, bstSearch(root, val)->key );
	
	return 0;
}

