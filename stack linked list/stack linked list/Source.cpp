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
	t->data = item;  //new一個新串列t，t設值為item
	t->link = top;   //t link指向top
	top=t;			 //讓t當作stack的top，top++
}
void pop() {
	Node* t = top;   //t抓取top的list
	if (isempty()) {
		printf("堆疊為空");
	}
	else {
		top = top->link; //top往下,top--
		t->link = NULL;	 //抓取的t節點設NULL
		delete(t);		 //刪除t
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
		printf("堆疊為空");
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
	Node* current = top; //current指向top
	Node* next = NULL;
	if (current == NULL) {
		printf("堆疊為空");
	}
	else {
		while (current != NULL) {
			next = current->link;    //next往下走,指向current的link
			current->link = pre;	 //current的link指向pre
			pre = current;           //pre往下走
			current=next;			 //current往下走
		}
		top = pre;
	}
}
