#include<stdio.h>
class Node{
public:
	int data;
	Node* link;
};

Node * concat(Node* a, Node* b, Node* d);
void add(Node* x, int item);
void print(Node* x);
Node* a=new Node();
Node* b=new Node();
Node* c=new Node();
Node* d = new Node();
int main() {
	a->link = NULL;
	add(a, 5);add(a, 10);add(a, 15);add(a, 20);
	Node* current = new Node();
	current->data = 10;
	if (a->link == NULL) {
		a = current;
	}
	else
	{
		while (a->link != NULL) {
			a = a->link;
		}
	}
	a->link = current;
	add(b, 6); add(b, 12); add(b, 18); add(b, 24);
	add(c, 7); add(c, 14); add(c, 21); add(c, 28);
	d = concat(a, b,d);
	print(a);
	print(b);
	print(c);
	print(d);
}

void add(Node* x, int item) {      
	Node* current = new Node();
	current->data = item;
	if (x->link == NULL) {

		x = current;
	}
	else
	{
		while (x->link != NULL) {
			x = x->link;
		}
	}
	x->link = current;


}

Node *  concat(Node* a, Node* b, Node* d) {
	Node* p = a;
	while (p->link != NULL)
		p = p->link;
	p->link = b;
	d = a;
	return d;
}

void print(Node * x) {
	Node* current = x;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->link;
	}
	printf("\n");
}