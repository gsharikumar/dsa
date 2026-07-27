#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct Node {
	int data;
	struct Node* next;
}node;

typedef struct Stack {
	node* head;
}stack;

stack* create_stack()
{
	stack* s = malloc(sizeof(stack));
	return s;
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

int push(stack *s, int data)
{
	node* n = create_node(data);
	if (n == NULL)
	{
		return -1;
	}
	if (s->head == NULL)
	{
		s->head = n;
		return 0;
	}
	n->next = s->head;
	s->head = n;

}

int pop(stack* s, int data)
{

}