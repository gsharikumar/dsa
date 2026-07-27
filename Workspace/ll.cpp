// ll.cpp
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))

struct Node {
	int data;
	Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

Node* createList(int *arr,int arrLen) {
	if (arrLen <= 0) {
		return NULL;
	}
	Node *head = new Node(arr[0]);
	Node *curr = head;
	for (int i = 1; i < arrLen; i++) {
		curr->next = new Node(arr[i]);;
		curr = curr->next;
	}
	return head;
}



void destoryList(Node *head) {
	Node *curr = head;
	while (curr != NULL) {
		Node *tmp = curr;
		curr = curr->next;
		delete (tmp);
	}
}

void printList(Node *head) {
	Node *curr = head;
	while (curr != NULL) {
		cout << curr->data << ", ";
		curr = curr->next;
	}
	cout << endl;
}

void printListRecur(Node *node) {
	if (node == NULL) {
		return;
	}
	cout << node->data << ", ";
	printListRecur(node->next);
	return;
}

void insertBegin(Node **head,int data) {
	if (*head == NULL) {
		return;
	}
	Node *newNode = new Node(data);
	newNode->next = *head;
	*head=newNode;
	return;
}

void insertEnd(Node *head, int data) {
	if (head == NULL) {
		return;
	}
	Node *curr = head;
	Node *prev= head;
	while (curr != NULL) {
		prev = curr;
		curr= curr->next;

	}
	Node *newNode = new Node(data);
	prev->next = newNode;
	return;
}

int searchNode(Node *head, int data)
{
	Node *curr=head;
	int index = 0;
	while (curr) {
		index++;
		if (curr->data == data) {
			return index;
		}
		curr = curr->next;
	}
	return -1;
}

int searchNodeRecur(Node *curr, int data,int index=0)
{
	if (!curr) {
		return -1;
	}
	index++;
	if (curr->data == data) {
		return index;
	}
	return  searchNodeRecur(curr->next, data,index);
}

int reverseList(Node* head)
{
	Node* front;
	Node* back = NULL;
	Node* curr = head;
	while (curr != NULL)
	{

		front = curr->next;
		curr->next = back;
		back = curr;
		curr = front;
	}
	printList(back);
	return 0;
}

Node* pairwiseSwap(Node* head) {
	// code here
	Node* left;
	Node* right;
	Node* curr = head;
	Node* prev = NULL;
	Node* retLL = NULL;
	while (curr != NULL && curr->next != NULL)
	{

		right = curr->next;
		left = curr;

		curr = right->next;

		left->next = right->next;
		right->next = left;

		//left becomes right and right become left
		if (!retLL)
		{
			retLL = right;
		}
		
		if (prev)
		{
			prev->next = right;
		}
		prev = left;


	}
	//printLL(retLL);
	return retLL;

}

void ll() {
	int arr[] = {1,2,3,4,5};
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	Node *head=createList(arr,arrLen);

	printList(head);
	pairwiseSwap(head);
	printList(head);


	return;

	reverseList(head);

	int nodeData = 6;
	cout<< "Node with data " << nodeData << " found at index iter method "<< searchNodeRecur(head, nodeData) << " recur method " << searchNodeRecur(head, nodeData) << endl;
	return;
	insertBegin(&head ,-1);
	insertEnd(head, 10);
	printList(head);
	insertBegin(&head, -2);
	insertEnd(head, 11);
	printList(head);
	destoryList(head);
	return;
}