#include<stdio.h>
#include<stdlib.h>

int f(int n,int m) { //non-recrusive
	int a=1, b=1, c=1;
	for (int i = 1; i <= n; i++) //n!
		a *=i;
	for (int i = 1; i <= m; i++) //m!
		b *=i;
	for (int i = 1; i <= (n - m); i++) //n-m!
		c *=i;
	return a/(b*c); //n!/m!*(n-m)!

}
/*
int f int (int n,int m){ //recrusive
if (n==0||n==m)
return 1;
else
return f(n-1,m)+f(n-1,m-1);

}
*/

int main() {
	printf("%d", f(5, 2));

}