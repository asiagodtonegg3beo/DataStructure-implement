#include<stdio.h>
class Node {

public:
	int data;
	Node* next;
};
void printList(Node* node);
void push(Node** head_ref, int new_data);
void pushfront(Node* x, int item);
int main() {

	Node* a = new Node;
	a->data = 10;
	a->next = NULL;
	push(&a, 5);
	printList(a);
}

void pushfront(Node* x, int item) {
	Node* current = new Node();
	current->data = item;
	current->next = x;
	x = current;
}

void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

void push(Node* head_ref, int new_data)
{
	/* 1. allocate node */
	Node* new_node = new Node();

	/* 2. put in the data */
	new_node->data = new_data;

	/* 3. Make next of new node as head */
	new_node->next = head_ref;

	/* 4. move the head to point to the new node */
	head_ref = new_node;
}