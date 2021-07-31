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
		rear->next = t;   //rear往後一格給t放
		rear = t;		  //rear設成t
		}
}
void del() {
	Node* t = front;	  //配置t指向front
	front = front->next;  //front前進一格
	if (front == NULL)	  //如果front為空，rear也設為空
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

