#include<stdio.h>
#define max 3 //�i�s2��A�����W�C�u��ϥ�n-1��
/*
1.n��u���n-1��
2.�ﵽlinear queue add���D�Aadd�Bdelete =>O(1) 
3.empty�Bfull �P�O�ۦP
*/
int front=0, rear=0; 
int queue[max] = { 0 };
void add(int n);
void del();
bool isfull();
bool isempty();
int n = max;
int main(void) {
	add(5);
	add(3);
	add(8);
	del();
	del();
	del();

}

void add(int n) { //�p�G���\add�Arear+1��A���l��
	if (isfull()) {
		printf("isfull\n");
	}
	else {
		queue[rear] = n;
		printf("insert element %d\n", queue[rear]);
		rear = (rear + 1) % n;
	}
}

void del() { //���\�R���Afront+1����l��
	if (isempty()) {
		printf("isempty\n");
	}
	else {
		printf("delete element %d\n", queue[front]);
		front = (front+1) % n;
	}
}

bool isfull() { //�ϥ�temp����rear+1��A�p�Gtemp��front�ۦP�A�hreturn true
	int temp_rear = (rear+1) % n;
	if (temp_rear == front)
		return true;
	else return false;
}

bool isempty() { //�P�_front=rear�A�۵�return true
	if (front == rear)
		return true;
	else return false;
}