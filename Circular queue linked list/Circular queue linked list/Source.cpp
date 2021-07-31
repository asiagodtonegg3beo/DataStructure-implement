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
	if (rear == NULL) {		//如果rear為空
		t->next = t;        //t的link接t的頭
		rear = t;			//rear設成t
	}
			
	else {
		t->next = rear->next; //t的link連接rear的link(尾接頭)
		rear->next = t;       //rear的link接到t的頭
		rear = t;			  //rear設成t
	}
}

void del() {
	if (rear == NULL)
		return;
	else {
		Node* t = rear->next;		//t指向front(rear->next，頭)
		rear->next = (rear->next)->next;  //rear的link指向front的link(頭+1)
		if (rear == t)              //如果rear跟t一樣，則rear=NULL(沒有元素了)
			rear = NULL;
		delete(t);
	}

}

void print() {
	if (rear == NULL) {
		printf("佇列已空");
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
