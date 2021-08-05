#include<stdio.h>
using namespace std;
class Node{
public:
	int data;
	Node* rlink;
	Node* llink;
	void add(int item);
	void delfront();
	void delrear();
	void print();
	void reverseprint();
	void addfront(int item);
};

Node* x = new Node();
Node* current = x;
Node* next = x->rlink;
Node* previous = x->llink;
Node* head = NULL;
Node* tail = NULL;
int main() {/*
	Node* t = new Node();
	t->data = 5;
	t->llink = NULL;
	t->rlink = NULL;
	x = t;*/





	x->addfront(1);
	x->add(4); x->print();
	x->add(8); x->print();
	x->add(7); x->print();
	x->add(6); x->print();
	x->add(3); x->print();

	x->print();
	x->reverseprint();


	x->delfront(); x->print(); x->reverseprint();
	x->delrear(); x->print(); x->reverseprint();
	x->addfront(1); x->print(); x->reverseprint();
}
	



void Node::add(int item) {
	Node *t = new Node;
	t->data = item;
	t->llink = NULL;
	t->rlink = NULL;
	if ((x->data==NULL)&&(x->llink == NULL)&&(x->rlink == NULL)) {
		head = tail = x = t; //ÀY¡B§À¡Bx³]¦¨t
	}
	else {
		x->rlink = t;
		(x->rlink)->llink = x;
		(x->rlink)->rlink = NULL;
		tail = x = t;
	}
}
void Node::addfront(int item) {
	Node* t = new Node;
	t->data = item;
	t->llink = NULL;
	t->rlink = NULL;

	if ((x->data == NULL) && (x->llink == NULL) && (x->rlink == NULL)) {
		head = tail = x = t;
	}
	else {
		x = head;
		t->rlink = x;
		x->llink = t;
		t->llink = NULL;
		head = x = t;
	}
}
void Node::delfront() {
	Node* current = head;
	Node* t = current;
	head = current = current->rlink;
	head->llink = current->llink = NULL;
	t->rlink = NULL;
	delete(t);
}

void Node::delrear() {
	Node* current = tail;
	Node* t = current;
	tail = current = current->llink;
	tail->rlink = current->rlink = NULL;
	t->llink = NULL;
	delete(t);
}

void Node::print() {
	Node* current = head;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->rlink;
	}
	printf("\n");
}

void Node::reverseprint() {
	Node* current = tail;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->llink;
	}
	printf("\n");

}