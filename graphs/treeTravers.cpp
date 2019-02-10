#include <iostream>
using namespace std;;
/*
1. create template<typendame T> struct Node {T data; Node* left; Node* right;
						Node(T data, Node* left=NULL, Node* right=NULL){init all}}
2. inorder - 1-left first then 2-root then 3-right
	void inorderTrav(Node<int>* root) {if (root) inorderTrav(root->left); cout << root->data; inorderTrav(r->right)}
3. preorder - 1-root will be traversal fist then 2-left then 3-right
4. postorder - 3-root in the end, first 1-rigth 2-left
*/

template<typename T>
struct Node {
	T data;
	Node *left;
	Node *right;
	Node (T data, Node* left=NULL, Node* right=NULL) {
		this->data = data;
		this->left = left;
		this->right = right;;
	}
};

void inorderTravers(Node<int>* root) 
{	
	if (root !=NULL) {
		inorderTravers(root->left);
		cout << root->data << endl;
		inorderTravers(root->right);
	}
}

void postorderTraversal(Node<int>* root)
{
	if (root) {
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		cout << root->data << endl;
	}
}

void preorderTraversal(Node<int>* root)
{
	if (root) {
		cout << root->data << endl;
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

int
main()
{
	Node<int> t1(1), t2(2), t3(3), t4(4), t5(5);
	t1.left=&t2;
	t1.right=&t3;
	t2.left=&t4;
	t2.right=&t5;
	cout << "print inorder "<<endl;
	inorderTravers(&t1);
	cout << "print preorder"<<endl;
	preorderTraversal(&t1);
	cout << "print postorder"<<endl;
	postorderTraversal(&t1);
	
}
