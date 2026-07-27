// bt.cpp
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))



struct Node {
	int key;
	Node* left;
	Node* right;
	Node(int k) {
		key = k;
		left = right = NULL;
	}
};

Node* getSuccessor(Node* root) {
	Node* curr = root->right;
	while (curr != NULL && curr->left != NULL) {
		curr = curr->left;
	}
	return curr;
}

Node* bstInsertRecur(Node* root, int k) {
	if (root == NULL) {
		return new Node(k);
	}
	if (root->key > k) {
		root->left=bstInsertRecur(root->left,k);
	}
	else {
		//if (root->key < k) 
		root->right = bstInsertRecur(root->right, k);
	}
	return root;
}

bool bstSearchRecur(Node* root, int k) {
	Node* curr = root;
	if (root == NULL) {
		return false;
	}
	if (root->key > k) {
		return bstSearchRecur(root->left, k);
	}
	else if (root->key < k) {
		return bstSearchRecur(root->right, k);
	}
	else {
		return true;
	}
	return false;
}

Node* bstDeleteRecur(Node* root, int k) {
	if (root == NULL) {
		return NULL;
	}
	if (root->key > k) {
		root->left = bstDeleteRecur(root->left, k);
	}
	else if (root->key < k) {
		root->right = bstDeleteRecur(root->right, k);
	}
	else {
		//match found
		if (root->left == NULL) {
			Node* tmp = root->right;
			delete root;
			return tmp;
		}
		else if (root->right == NULL) {
			Node* tmp = root->left;
			delete root;
			return tmp;
		}
		else {
			//(root->left && root->right)
			/* successor is the node with key value that produce positive minimum difference
				* which is left leaf node of the root's right node
				* also getSuccessor works only if the right node is not empty, which is gaurenteed here
			*/
			Node* scr = getSuccessor(root);
			int scrKey = scr->key;
			root->right = bstDeleteRecur(root->right, scrKey); //why assignment 
			root->key = scrKey;
		}
	}
	return root;
}


void bstInsert(Node** root, int k) {
	if (*root==NULL) {
		*root =new Node(k);
		return;
	}
	Node* curr = *root;
	Node* parent = *root;
	while (curr!=NULL) {
		//iterate to the appropriate leaf node, which is updated in parent
		parent = curr;
		if (curr->key > k) {
			curr = curr->left;
		}
		else// if (curr->key > k) 
		{
			curr = curr->right;
		}
	}
	if (parent->key < k){
		//insert to right of parent
		parent->right = new Node(k);
	}
	else {
		parent->left = new Node(k);
	}
	return;
}



void bstPrint(Node *root) {
	Node* curr = root;
	if (root == NULL){
		return;
	}
	bstPrint(root->left);
	cout << root->key << ", ";
	bstPrint(root->right);
	return;
}
#if 0
struct TreeNode* prev = NULL;

void flatten(struct TreeNode* root) {
	if (root == NULL) {
		return;
	}

	// Recursively flatten the right subtree first
	flatten(root->right);

	// Recursively flatten the left subtree
	flatten(root->left);

	// After subtrees are flattened, link the current node
	// to the previously processed node (which is the head of the
	// already flattened right/left subtree from the previous step)
	root->right = prev;
	root->left = NULL; // Left child should always be NULL for the linked list

	// Update the 'prev' pointer to the current node for the next call
	prev = root;
}


void bst_flatten_recur
{

}
#endif
void bst() {
	Node* root = NULL;
	int arr[] = { 10,20,30,40,50,70,80,60 }; //inorder left root right
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < arrLen; i++) {
		bstInsert(&root, arr[i]); //iterative
		//root=bstInsertRecur(root, arr[i]);
	}
	bstPrint(root); cout << endl;
	root=bstDeleteRecur(root, 10);
	bstPrint(root); cout << endl;
	root = bstDeleteRecur(root, 60);
	bstPrint(root); cout << endl;

	
//	delete(root, 20);
	//destoryBSTList(root);
	return;
}
