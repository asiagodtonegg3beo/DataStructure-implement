#include<stdio.h>
#define max 3 //可存2格，環狀柱列只能使用n-1格
/*
1.n格只能用n-1格
2.改善linear queue add問題，add、delete =>O(1) 
3.empty、full 判別相同
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

void add(int n) { //如果成功add，rear+1格，取餘數
	if (isfull()) {
		printf("isfull\n");
	}
	else {
		queue[rear] = n;
		printf("insert element %d\n", queue[rear]);
		rear = (rear + 1) % n;
	}
}

void del() { //成功刪除，front+1格取餘數
	if (isempty()) {
		printf("isempty\n");
	}
	else {
		printf("delete element %d\n", queue[front]);
		front = (front+1) % n;
	}
}

bool isfull() { //使用temp偷看rear+1格，如果temp跟front相同，則return true
	int temp_rear = (rear+1) % n;
	if (temp_rear == front)
		return true;
	else return false;
}

bool isempty() { //判斷front=rear，相等return true
	if (front == rear)
		return true;
	else return false;
}