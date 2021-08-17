#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int non_sential(int* data, int n, int key);//O(n)
int sential(int* data, int key,int n); //效率佳，多一個判斷空間，O(n)
int *sort(int* data,int n,string ch);
int BS_it(int* data, int key, int l, int u); //l=lower,u=upper，採疊代方法，O(logn)
int BS_r(int* data, int key, int l, int u); //採遞迴方法，Binary Search 需先排序
int main() {
	int data[10] = { 8,5,7,1,4,6,3,2,9,10 };
	int data_2[10+1];
	data_2[0] = 0;
	memmove(data_2+1, data, sizeof(data));
	int n = sizeof(data) / sizeof(int);
	int key = 5;
	//((non_sential(data, n, key)>-1) ? printf("found %d,index = %d", data[non_sential(data, n, key)], non_sential(data, n, key)) : printf("not found"));
	printf("\n");
	key = 0;
	//sential(data_2, key,n+1) ? cout << "found " << data_2[sential(data_2, key,n+1)] << " index= " << sential(data_2, key,n+1) : cout << "not found" << endl;
	string ch = "min";
	int *p = sort(data,n,ch);
	
	memmove(data, p, sizeof(p));

	for (int i = 0; i < n; i++) {
		printf(" %d ", *(p + i));
	}
	cout << endl;
	BS_r(data, 5, 0, n);

}

int non_sential(int *data,int n, int key) {
	int i = 0;
	while (i < n) {
		if (data[i] == key) {
			return i;
		}
		else {
			i++;
		}
	}
	return -1;
}

int sential(int data[],int key,int n) {
	int i = n;
	data[0] = key;
	while (data[i]!=key) {
		i--;
	}

	return i;
}

int *sort(int* data, int n, string ch) {
	int temp;
	if (ch == "min") {
		for (int i = 0; i < n-1; i++) {
			for (int j = i+1; j < n; j++) {
				if (data[i] > data[j]) {
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	}
	if (ch == "MAX") {
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (data[i] < data[j]) {
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	}

	return data;
}

int BS_it(int *data, int key, int l, int u) {
	while (l <= u) {
		int mid = (l + u) / 2;
		if (key==data[mid]) {
			printf("find %d index= %d", data[mid], mid+1);
			return mid;
		}
		else if (key > data[mid]) {
			l = mid + 1;
		}
		else {
			u = mid - 1;
		}
	}
	printf("not found");
	return -1; //未找到
}

int BS_r(int* data, int key, int l, int u) {
	int mid = (l + u) / 2;
	if (data[mid] == key) {
		printf("find %d index = %d", data[mid], mid + 1);
		return mid;
	}
	else if (key > data[mid]) {
		return BS_r(data, key, l + 1, u);
	}
	else {
		return BS_r(data, key, l, u - 1);
	}
	printf("not found");
	return -1;
}