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
		hanoi(n - 1, A, C, B); //����n-1�ӽL�l�qA��B,�ȦsC
		printf("move disk %d from %c to %c\n", n, A, C);
		hanoi(n - 1, B, A, C); //����n-1�ӽL�l�qB��C,�ȦsA
	
	}

}