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




Node* createBTList(int *arr,int arrLen) {
	if (arrLen <= 0) {
		return NULL;
	}
	Node *head = new Node(arr[0]);
	head->left= new Node(arr[1]);
	head->right = new Node(arr[2]);
	head->left->left = new Node(arr[3]);
	head->left->right = new Node(arr[4]);
	head->left->right->left = new Node(arr[5]);
	head->left->right->right = new Node(arr[6]);
	head->right->right = new Node(arr[7]);

	return head;
}



void destoryBTList(Node *head) {
	Node *curr = head;
	while (curr != NULL) {
		Node *tmp = curr;
		delete (tmp);
	}
}

void printBTList(Node *head) {
	Node *curr = head;
	while (curr != NULL) {
		cout << curr->key<< ", ";
		curr = curr->left;
	}
	cout << endl;
}

void printBTListRecur(Node *root) {
	if (root == NULL) {
		return;
	}
	/*
	possible print options possible 3! for left, right root 
	taking left as first below are the 3 ways
	time complexity - O(n)  where n ->no of nodes
	space complexity - O(h) where h ->height of the tree actual complexity h+1
	*/
#ifdef PREORDER
	//pre order implementation
	//root-left-right
	cout << root->key << ", ";
	printBTListRecur(root->left);
	printBTListRecur(root->right);
#elif POSTORDER
	//post order implementation
	//left-right-root
	printBTListRecur(root->left);
	printBTListRecur(root->right);
	cout << root->key << ", ";
#else
	//inorder implementation
	//left-root-right
	printBTListRecur(root->left);
	cout << root->key << ", ";
	printBTListRecur(root->right);
#endif
	return;
}

int getBTListHeight(Node* root) {
	/*	
	time complexity - O(n)  where n->no of nodes
	space complexity - O(h) where h->height of the tree actual complexity h + 1
	*/
	if (root == NULL) {
		return 0;
	}
	int ret = 0;
	int retLeft;
	int retRight;
	retLeft = getBTListHeight(root->left);
	retRight = getBTListHeight(root->right);
	ret = MAX(retLeft, retRight)+1;
	return ret;
}

void printBTNodesAtHeight(Node* root, int targetH, int currH = 0) {
	/*
	* print all nodes in specific level
	* implementation without using currH argument is possible look at printBTNodesAtHeightOpt() implementation
	* time complexity O(n)
	* space complexity O(h)
	*/
	
	if (root == NULL) {
		return;
	}
	if (currH == targetH) {
		cout << root->key << ",";
	}
	else if (currH < targetH) {
		printBTNodesAtHeight(root->left, targetH, currH+1);
		printBTNodesAtHeight(root->right,targetH,currH+1);
	}
	return;
}

void printBTNodesAtHeightOpt(Node* root, int targetH) {
	/*
	* print all nodes in specific level
	* implementation without using currH argument
	*/

	if (root == NULL) {
		return;
	}
	if (targetH == 0) {
		cout << root->key << ",";
	}
	else {
		printBTNodesAtHeight(root->left, targetH-1);
		printBTNodesAtHeight(root->right, targetH-1);
	}
	cout << endl;
	return;
}

void printBTLevelOrder(Node* root) {
	/*
	* print all nodes in level order
	* sub optimal algo O(h*n) - brute force
	* optimal algo time & space complexity O(n)
	* to be more precise space complexity (queue size) 
	* best case is omega-W(1) 
	* worst case theta(max width) max-width=2^h -> happens in balanced tree
	* max width of the binary tree is 2^h gives the nodes at the last level
	* 
	*/

	if (root == NULL) {
		return;
	}
	int i = 0;
	int j = 0;
	queue < Node* > q;
	q.push(root);
	while (q.empty() == false) {
		Node* curr = q.front();
		cout << curr->key << "," ;
		q.pop();
		if (curr->left) {
			q.push(curr->left);
		}
		if (curr->right) {
			q.push(curr->right);
		}

		/*
		//below code works only for balanced binary tree
		i++;
		if (i == pow(2,j)) {
			cout << endl;
			j++;
			i = 0;
		}
		*/
	}
	return;
}


void printBTLevelOrderSeperatedByNextLineMethod1(Node* root) {
	/*
	* print all nodes in level order, each level seperated by next line
	* sub optimal algo O(h*n) - brute force
	* optimal algo time complexity O(n)
	* space complexity is equal queue size
	* best case is omega(1) - more precise
	* worst case theta(max-width+1) max-width=2^h -> happens in balanced tree
	* max width of the binary tree is 2^h gives the nodes at the last level
	* +1 is to accomodate the NULL
	*/

	if (root == NULL) {
		return;
	}
	queue < Node* > q;
	q.push(root);
	q.push(NULL);
	while (q.size() > 1) {
		Node* curr = q.front();
		q.pop();
		if (curr == NULL) {
			q.push(NULL);
			cout << endl;
			continue;
		}
		cout << curr->key << ",";
		if (curr->left) {
			q.push(curr->left);
		}
		if (curr->right) {
			q.push(curr->right);
		}
	}	
	return;
}

void printBTLevelOrderSeperatedByNextLineMethod2(Node* root) {
	/*
	* print all nodes in level order, each level seperated by next line
	* sub optimal algo O(h*n) - brute force
	* optimal algo time complexity O(n)
	* space complexity is equal queue size
	* best case is omega(1) - more precise
	* worst case theta(max-width) max-width=2^h -> happens in balanced tree
	* max width of the binary tree is 2^h gives the nodes at the last level
	* no +1 is to accomodate the NULL in method2 
	*/

	if (root == NULL) {
		return;
	}
	queue < Node* > q;
	q.push(root);
	while (q.empty()==false) {
		int count = q.size();
		for (int i = 0; i < count; i++) {
			Node* curr = q.front();
			q.pop();
			cout << curr->key << ",";
			if (curr->left) {
				q.push(curr->left);
			}
			if (curr->right) {
				q.push(curr->right);
			}
		}
		cout << endl;
	}
	return;
}

int printBTSizeRecur(Node* root) {
	/*
	time complexity O(n)
	space complexity - stack usage on making recursive function calls O(h+1)= O(h) +1 is for the function called with null
	*/
	if (root==NULL) {
		return 0;
	}
	int leftSize = printBTSizeRecur(root->left);
	int rightSize = printBTSizeRecur(root->right);
	return leftSize + rightSize+1;

}

int printBTSizeIter(Node* root) {
	/*
	* follow level order printing which uses queue
	* time complexity O(n)
	* space complexity O(maxwidth)
	*/
	int count=0;
	if (root == NULL) {
		return count;
	}
	queue <Node*> q;
	q.push(root);
	while(q.empty()==false){
		Node* curr = q.front();
		count++;
		q.pop();
		if (curr->left) {
			q.push(curr->left);
		}
		if (curr->right) {
			q.push(curr->right);
		}
	}
	return count;
}

int printBTMaxIter(Node* root) {
	/*
	* follow level order printing which uses queue
	* time complexity O(n)
	* space complexity O(maxwidth)
	*/
	int max = INT_MIN;
	if (root == NULL) {
		return INT_MIN; //important
	}
	queue <Node*> q;
	q.push(root);
	while (q.empty() == false) {
		Node* curr = q.front();
		max = MAX(max, curr->key);
		q.pop();
		if (curr->left) {
			q.push(curr->left);
		}
		if (curr->right) {
			q.push(curr->right);
		}
	}
	return max;
}

int maxLevel = 0;
void printBTLeftViewRecur(Node* root,int level=1) {
	/*
	* time O(n)
	* space O(h)
	*/
	if (root == NULL) {
		return;
	}
	if (maxLevel < level) {
		cout << root->key << ",";
		maxLevel = level;
	}
	printBTLeftViewRecur(root->left,level+1);
	printBTLeftViewRecur(root->right,level+1);
	return;
}

void printBTLeftViewIter(Node* root) {
	/*
	* time O(n)
	* space O(w)
	*/
	if (root == NULL) {
		return;
	}
	queue <Node*> q;
	q.push(root);

	while (q.empty() == false) {
		int count = q.size();
		for (int i = 0; i < count; i++) {
			Node* curr = q.front();
			q.pop();
			if (!i) {
				cout << curr->key << ",";
			}
			if (curr->left) {
				q.push(curr->left);
			}
			if (curr->right) {
				q.push(curr->right);
			}
		}
	
	}
	return;
}


bool isBTFollowChildSumProperty(Node* root) {
	/*
	* first try
	* note test!!!!!!!!!!!!
	* child sum property
	* left(child)+right(child)=node (parent)
	* time O(n)
	* space O(h)
	* 
	*/

	if (root == NULL) {
		//empty node then follows child sum property
		return true;
	}
	if (root->left == NULL && root->right == NULL) {
		//only single node then follows child sum property
		return true;
	}
	bool bRet=false;
	if (root->left && root->right) {
		if (root->key == (root->left->key + root->right->key)) {
			bool bLeftStatus = isBTFollowChildSumProperty(root->left);
			bool bRightStatus = isBTFollowChildSumProperty(root->right);
			bRet = bLeftStatus && bRightStatus;
		}
	}
	else if (root->left) {
		if (root->key == root->left->key) {
			bRet = isBTFollowChildSumProperty(root->left);
		}
	}
	else {
		if (root->key == root->right->key) {
			bRet = isBTFollowChildSumProperty(root->right);
		}
	}
	return bRet;
}

bool isBTFollowChildSumPropertyReducedLines(Node* root) {
	/*
	* note test!!!!!!!!!!!! follow GG
	* child sum property
	* left(child)+right(child)=node (parent)
	* time O(n)
	* space O(h)
	*
	*/

	if (root == NULL) {
		//empty node then follows child sum property
		return true;
	}
	//base condition below is very important
	if (root->left == NULL && root->right == NULL) {
		//only single node then follows child sum property
		return true;
	}
	int sum = 0;
	bool bRet = false;
	if (root->left) {
		sum += root->left->key;
	}
	if (root->right) {
		sum += root->right->key;
	}
	if (root->key == sum) {
		bool bLeftStatus = isBTFollowChildSumProperty(root->left);
		bool bRightStatus = isBTFollowChildSumProperty(root->right);
		bRet = bLeftStatus && bRightStatus;
	}
	return bRet;
}

bool isBTBalancedBruteForce(Node* root) {
	/*
	* note test!!!!!!!!!!!!
	* time O(n^2)
	* space O(h)
	*/
	if (root == NULL) {
		return true;
	}
	bool bRet = false;
	int leftH=getBTListHeight(root->left);
	int rightH = getBTListHeight(root->right);
	if (abs(leftH - rightH) <= 1) {
		bRet = isBTBalancedBruteForce(root->left) && isBTBalancedBruteForce(root->right);
	}
	return bRet;
}

int isBTBalancedOptimal(Node* root) {
	/*
	* note test!!!!!!!!!!!! followed GG
	* time O(n)
	* space O(h)
	*/
	if (root == NULL) {
		return true;
	}
	int lRet = isBTBalancedOptimal(root->left);

	if (lRet < -1) {
		return -1;
	}
	int rRet = isBTBalancedOptimal(root->right);
	if (rRet < -1) {
		return -1;
	}
	if (abs(lRet - rRet) > 1) {
		return -1;
	}
	return (MAX(lRet, rRet) + 1);
}

int maxWidthBT(Node* root) {
	if (root == NULL) {
		return 0;
	}
	queue <Node*> q;
	q.push(root);
	int maxWidth = 0;
	while (q.empty() == false) {
		int count = q.size();
		maxWidth = MAX(count,maxWidth);
		for (int i = 0; i < count; i++) {
			Node* curr = q.front();
			q.pop();
			if (curr->left) {
				q.push(curr->left);
			}
			if (curr->right) {
				q.push(curr->right);
			}
		}
	}
	return maxWidth;
}


Node* convertBT2DLL(Node* root) {
	/*
	* Crazy!! Very non intutive, not sure how I would have solved, if I had not seen the solution from GG
	* time O(n)
	* space O(h)
	*/
	static Node* prv = NULL;
	if (root == NULL) {
		return NULL;
	}
	Node *head= convertBT2DLL(root->left);
	if (prv == NULL) {
		head = root;
	}
	else {
		root->left = prv;
		prv->right = root;
	}
	prv = root;
	convertBT2DLL(root->right);
	return head;
}

Node* constructBTFromInorderPreOrderArr() {
	/*
	* exercise pending - refer to GG video for example
	*/
	int inorderArr[] = {20,10,40,30,50};
	int preOrderArr[] = { 10,20,30,40,50 };

	return NULL;
}



int findHeightOfLeftBranchRecur(Node* root) {
	if (root == NULL) {
		return 0;
	}
	return (1+ findHeightOfLeftBranchRecur(root->left));
}

int findHeightOfRightBranchRecur(Node* root) {
	if (root == NULL) {
		return 0;
	}
	return (1 + findHeightOfRightBranchRecur(root->right));
}


int countNodeInCompleteBT(Node* root) {
	if (root) {
		return 0;
	}
	int nodeCnt = 1;
	/*not tested!!!
	* time O(logn*logn) --> study this later
	* 
	* iter method to find height - this is better
	* Node* curr=root;
	* int lCnt=0;
	* while(curr){
	* lCnt++;
	* curr=curr->left;
	* }
	*/
	int leftH = findHeightOfLeftBranchRecur(root->left); 
	int rightH= findHeightOfRightBranchRecur(root->right);
	if (leftH == rightH) {
		nodeCnt += (pow(2, leftH) - 1); //important  2^lH-1 +2^lR-1 -- totally wrong!!!!!!!
	}
	else {
		nodeCnt += countNodeInCompleteBT(root->left);
		nodeCnt += countNodeInCompleteBT(root->right);
	}
	return nodeCnt;
}

int burnBinaryTreeFromLeafTimeTaken(Node *root) {
	/*
	* pending!!!
	* 
	* 
	*/
	if (root == NULL) {
		return 0;
	}
	//int lCnt = burnBinaryTreeFromLeafTimeTaken(root->left);
	//int rCnt = burnBinaryTreeFromLeafTimeTaken(root->right);


	//return MAX(lCnt,rCnt)
}

void bt() {
	int arr[] = { 10,20,30,40,50,70,80,60 }; //inorder left root right
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	Node* root = createBTList(arr, arrLen);
	cout << "Inorder printing ";
	printBTListRecur(root);

	cout << endl<<"Height of BT " <<getBTListHeight(root)<<endl;

	cout << endl << "Height of BT";
	printBTNodesAtHeightOpt(root,3);
	
	cout << endl<<"Level order BT printing"<<endl;
	printBTLevelOrder(root);
	cout << endl<<"Level order BT printing seperated by next line" << endl;
	printBTLevelOrderSeperatedByNextLineMethod2(root);
	
	cout << endl << "BT total node count recur method=" <<printBTSizeRecur(root) <<" iter method="<< printBTSizeIter(root)<<endl;

	cout << endl << "max node = " << printBTMaxIter(root) << endl;

	cout << endl << "left view of BT recur method =";
	printBTLeftViewRecur(root);
	cout << endl << "left view of BT iter method = ";
	printBTLeftViewIter(root);

	cout << endl << "BT follows child sum property status "<< isBTFollowChildSumProperty(root);
	
	cout << endl << "BT max width " << maxWidthBT(root);
	
	cout << endl << "node count for complete binary tree optimized= " << countNodeInCompleteBT(root);
	//destoryBTList(root);
	return;
}
