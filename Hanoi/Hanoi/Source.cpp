#include<stdio.h>
void hanoi(int n, char A, char B, char C);

int main(void) {
	int n;
	char A='A',B='B',C='C';
	scanf_s("%d", &n);
	hanoi(n, A, B, C);

}

void hanoi(int n, char A, char B, char C) { // diskno,start,temp,distination
	if (n == 1)
		printf("move disk %d from %c to %c\n", n, A, C);
	else {
		hanoi(n - 1, A, C, B); //移動n-1個盤子從A到B,暫存C
		printf("move disk %d from %c to %c\n", n, A, C);
		hanoi(n - 1, B, A, C); //移動n-1個盤子從B到C,暫存A
	
	}

}