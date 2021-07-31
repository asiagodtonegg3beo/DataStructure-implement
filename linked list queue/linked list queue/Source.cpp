#include<iostream>
#include<cstdlib>

class Node {
public:
	int data;
	Node* next;
};

Node* front;
Node* rear;

void add(Node* t);
void add(int x);
void del();
void print();
int main() {

	add(5);
	add(7);
	add(8);
	add(9);
	add(1);
	print();
	del();
	del();
	del();
	print();



}

void add(Node* t) {
	if (rear == NULL)
		front = rear = t;
	else{
		rear->next = t;
		rear = t;
	}
}
void add(int x) {
	Node* t = new Node();
	t->data = x;
	if (rear == NULL) {
		rear = front = t;
}
	else {
		rear->next = t;   //rear����@�浹t��
		rear = t;		  //rear�]��t
		}
}
void del() {
	Node* t = front;	  //�t�mt���Vfront
	front = front->next;  //front�e�i�@��
	if (front == NULL)	  //�p�Gfront���šArear�]�]����
		rear = NULL;
	delete(t);
}

void print() {
	Node* t = front;
	while (t != NULL) {
		printf("%d ", t->data);
		t = t->next;
	}
	printf("\n");
}

