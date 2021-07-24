#include <stdio.h>

int max(int a, int b) {
	if (a > b) return a;
	else return b;

}

int f(int n,int m) { //(k+1)*...*n / (n-m)!
	int k, a = 1, b = 1;
	k = max(n - m, m);
	for (int i = k + 1; i <= n; i++)
		a *= i;
	for (int i = 1; i <= (n - m); i++)
		b *= i;
	return a / b;
}


int main()
{
	printf("%d", f(100,98));
}


