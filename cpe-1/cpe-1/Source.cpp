#include<stdio.h>
#include<iostream>
using namespace std;
int main() {
	int t;
	int m, d;
	int sum=0;
	string day[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	cin >> t;
	while (1) {
		cin >> m >> d;
		for (int i = 0; i < m; i++) {
			sum += month[i];
		}
		int ans = (sum+d+5) % 7;
		cout<<day[ans]<<endl;
		sum = 0;
	}

}