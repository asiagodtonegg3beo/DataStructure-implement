#include<stdio.h>
#define N 4
void push(int data);
void pop();
void print();
bool isfull();
bool isempty();
void reverse();//�����C
void show();

//���|���C
void add(int data); //�Ppush�ۦP
void del();

int i = 0;
int top = -1;
int stack[N];
int temp[N]; //�Ȧs��C
int main() {
	add(10);
	//show();
	//printf("top:%d\n", top);
	add(7);
	//show();
	//printf("top:%d\n", top);
	push(6);
	//show();
	//printf("top:%d\n", top);
	push(9);
	//show();
	//printf("top:%d\n", top);
	del();
	//show();
	//printf("top:%d\n", top);
	pop();
	//show();
	//printf("top:%d\n", top);
}

void push(int n) {
	if (isfull()) {
		printf("���|���F\n", n);

	}
	else {
		printf("add %d in stack\n", n);
		stack[++top] = n;
	}

}

void pop() {
	if (isempty()) {
		printf("���|���F");
	}
	else {
		printf("�R��%d\n", stack[top]);
		stack[--top];
	}
}

bool isfull() {
	if (top == N-1) {
		printf("is full\n");
		return 1;
	}
	else {
		return 0;
	}
}

bool isempty() {
	if (top == -1) {
		return 1;
	}
	else
		return 0;
}

void add(int data) {
	if (isfull())
		printf("���|���F");
	else {
		stack[++top]=data;
		printf("��C:�[�J%d\n", stack[top]);
	}
}

void del() {
	printf("��C:�R��%d\n", stack[0]);
	reverse();
	top--;

	for (i = 0;i<top;i++) {
		stack[i] = temp[top - i];
	}
	for (int i = 0; i <= top; i++)
		printf("%d ", temp[i]);
}


void reverse(){
	for (int i = 0;i<=top;i++) {
		temp[i] = stack[top - i];
	}
	/*for (int i = 0; i <= top; i++)
		printf("%d ", temp[i]);*/
}

void show() {
	for (int i = 0; i <= top; i++)
		printf("%d ", stack[i]);
}


