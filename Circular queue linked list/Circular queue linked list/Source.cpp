#include<stdio.h>
#include<stdlib.h>
class Node{
public:
	int data;
	Node* next;
};
Node* rear;
void create();
void add(int x);
void del();
void print();
int main() {
	add(8);
	print();
	add(7);
	print();
	add(10);
	print();
	add(12);
	print();
	del();
	print();
	del();
	print();
	del();
	print();
	del();
	print();
}

void create() {
	rear = NULL;
}

void add(int x) {
	Node* t = new Node();
	t->data = x;
	if (rear == NULL) {		//�p�Grear����
		t->next = t;        //t��link��t���Y
		rear = t;			//rear�]��t
	}
			
	else {
		t->next = rear->next; //t��link�s��rear��link(�����Y)
		rear->next = t;       //rear��link����t���Y
		rear = t;			  //rear�]��t
	}
}

void del() {
	if (rear == NULL)
		return;
	else {
		Node* t = rear->next;		//t���Vfront(rear->next�A�Y)
		rear->next = (rear->next)->next;  //rear��link���Vfront��link(�Y+1)
		if (rear == t)              //�p�Grear��t�@�ˡA�hrear=NULL(�S�������F)
			rear = NULL;
		delete(t);
	}

}

void print() {
	if (rear == NULL) {
		printf("��C�w��");
			return;
	}
	else
	{
		Node* t = rear->next;
		Node* tmp = t;
		do {
			printf("%d ", t->data);
			t = t->next;
		} while (t != tmp);
	}
	printf("\n");
}
