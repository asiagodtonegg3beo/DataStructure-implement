
#include <stdio.h>
//void create(int size);
int add(int n);
int max = 2;
int del();
int isfull();
int isempty();
int front=-1, rear=-1;
int size=0; //�j�p
int queue[10];

int main() {
	add(8);
	add(7);
	add(2);
	del();
	del();
	del();

}

int add(int n) { //�P�_�O�_���A�p�G�S���i�K�[
	if (isfull() == 1) {
		printf("��C�w��\n");
	}
	else {
		rear++;
		queue[rear] = n;
		printf("���\�W�[%d�bqueue\n", n);
		return n;
	}
}

int del() { //�P�_�O�_�šA�p�G�S�ťi�R��
	if (isempty() == 1) {
		printf("��C�w��\n");

	}
	else {
		front++;
		printf("���\�R��%d�bqueue\n",queue[front]);
		return queue[front];
	}

}

int isfull() { //rear+1��ܼƶq >=max�P�_��
	if (rear+1 >= max)
		return true;
	else
		return false;
}

int isempty() { //front=rear�h��ܪ�
	if (front == rear)
		return true;
	else
		return false;


}