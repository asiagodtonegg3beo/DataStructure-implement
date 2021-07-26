
#include <stdio.h>
//void create(int size);
int add(int n);
int max = 2;
int del();
int isfull();
int isempty();
int front=-1, rear=-1;
int size=0; //大小
int queue[10];

int main() {
	add(8);
	add(7);
	add(2);
	del();
	del();
	del();

}

int add(int n) { //判斷是否滿，如果沒滿可添加
	if (isfull() == 1) {
		printf("佇列已滿\n");
	}
	else {
		rear++;
		queue[rear] = n;
		printf("成功增加%d在queue\n", n);
		return n;
	}
	
}

int del() { //判斷是否空，如果沒空可刪除
	if (isempty() == 1) {
		printf("佇列已空\n");

	}
	else {
		front++;
		printf("成功刪除%d在queue\n",queue[front]);
		return queue[front];
	}
	if (front != -1) {//			n-1  O(n)
		for (int i = front + 1; i <= rear; i++) { //一個一個往前挪
			queue[i - (front + 1)] = i;
		}
		rear = rear - (front + 1); //front，rear調整
		front = -1;
	}
}

int isfull() { //rear+1表示數量 >=max判斷滿
	if (rear+1 >= max)
		return true;
	else
		return false;
}

int isempty() { //front=rear則表示空
	if (front == rear)
		return true;
	else
		return false;


}