#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct Node {
	int data;
	struct Node* next;
}node;

typedef struct Queue {
	node* head;
	node* tail;
};

queue* create_queue()
{
	queue* q = malloc(sizeof(queue));
	return q;
}

node* create_node(int data)
{
	node* n = malloc(sizeof(node));
	if (n)
	{
		n->data = data;
		n->next = NULL;
	}
	return n;
}

int enqueue(queue *q, int data)
{
	node* new_node = create_node(data);
	if (new_node == NULL) {
		return -1;
	}
	if (q->tail == NULL)
	{
		q->tail = q->head = new_node;
		return;
	}
	q->tail->next = new_node;
	q->tail = new_node;
	return 1;
}

int dequeue(queue *q)
{
	int data;
	//is_empty condition
	if (q->head == NULL)
	{
		return -1;
	}
	node* tmp = q->head;
	data = tmp->data;
	q->head = q->head->next;
	if (q->head == NULL)
	{
		q->tail = NULL;
	}
	free(tmp);
	return data;
}