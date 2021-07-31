#include<iostream>
#include<cstdlib>
class Node {
public:
	int data;
	Node* link;

};
void create();
void push(int item);
void pop();
int peek();
void print();
int isempty();
void reverse();
Node* top = NULL;

int main() {
	push(8);
	//print();
	push(7);
	//print();
	push(9);
	push(9);
	push(9);
	print();
	//pop();
	//print();
	//pop();
	//print();
	reverse();
	print();
}

void create() {
	top = NULL;
}

void push(int item) {
	Node* t = new Node();
	t->data = item;  //new�@�ӷs��Ct�At�]�Ȭ�item
	t->link = top;   //t link���Vtop
	top=t;			 //��t��@stack��top�Atop++
}
void pop() {
	Node* t = top;   //t���top��list
	if (isempty()) {
		printf("���|����");
	}
	else {
		top = top->link; //top���U,top--
		t->link = NULL;	 //�����t�`�I�]NULL
		delete(t);		 //�R��t
	}
}
int isempty() {
	if (top == NULL)
		return true;
	else
		return false;
}

int peek() {
	if (!isempty)
		return top->data;
}

void print() {
	Node* t = top;
	if (t == NULL) {
		printf("���|����");
	}
	else {
		while (t != NULL) {
			printf("%d ", t->data);
			t = t->link;
		}
		printf("\n");
	}
}

void reverse() {
	Node* pre = NULL;
	Node* current = top; //current���Vtop
	Node* next = NULL;
	if (current == NULL) {
		printf("���|����");
	}
	else {
		while (current != NULL) {
			next = current->link;    //next���U��,���Vcurrent��link
			current->link = pre;	 //current��link���Vpre
			pre = current;           //pre���U��
			current=next;			 //current���U��
		}
		top = pre;
	}
}
