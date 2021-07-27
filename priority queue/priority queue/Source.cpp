#include<stdio.h>
#define N 1
void push(int);
void pop();
void print();
bool isfull();
bool isempty();

int top = -1;
int stack[N];
/*
int main() {
	push(10);
	push(5);
	push(6);
	pop();
}
*/
void push(int n) {
	if (isfull() != 0) {
		printf("add %d in stack\n", n);
		stack[++top] = n;
	}

}

void pop() {
	if (isempty() != 0) {
		stack[++top];
	}
}

bool isfull() {
	if (top == N - 1) {
		printf("is full\n");
		return 0;
	}
	else {
		return 1;
	}
}

bool isempty() {
	if (top < 0) {
		printf("is empty\n");
		return 0;
	}
	else
		return 1;
}





int main() {

}