#include<stdio.h>       //top1從n/2中間--，top1從n/2+1中間++
#include<stdlib.h>
#define n 4
int s[n] = {0};
int size;
int top1 = n / 2; //top--
int top2 = n / 2 + 1; //top++
void push(int top,int data);
void pop(int top);
bool isfull1();
bool isempty1();
bool isfull2();
bool isempty2();
int main() {
	push(1, 50);
	push(2, 60);

	push(1, 40);
	push(2, 70);

	push(2, 70);
	pop(1);
	pop(1);
	pop(2);
	pop(2);
}

void push(int top, int data) {
	if (top == 1) {
		if (isfull1())
			printf("top1滿了\n");
		else {
			s[--top1] = data;
			printf("加入%d在top1\n",data);
		}
}
	else {
		if (isfull2())
			printf("top2滿了\n");
		else {
			s[++top2] = data;
			printf("加入%d在top2\n", data);
		}
	}

}

void pop(int top) {
	if (top == 1) {
		if (isempty1())
			printf("top1滿了\n");
		else {
			printf("刪除%d在top1\n", s[top1]);
			s[top1++];
		}

	}
	else {
		if (isempty2())
			printf("top2滿了\n");
		else {
			printf("刪除%d在top2\n", s[top2]);
			s[top2--];
		}

	}

}

bool isfull1() {
	if (top1 == -1)
		return 1;
	else
		return 0;
};

bool isfull2() {
	if (top2 == n+1)
		return 1;
	else
		return 0;
};

bool isempty1() {
	if (top1 == (n / 2))
		return 1;
	else
		return 0;
}

bool isempty2() {
	if (top2 == (n / 2 + 1))
		return 1;
	else
		return 0;
}

