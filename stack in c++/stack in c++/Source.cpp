#include<iostream>
#include<cstdlib>
#include <stack>
using namespace std;

int main(void) {
	stack<char> stack;
	char ch[] = "57+";
	int sum = 0;
	char op;
	int i = 0; 
	while (ch[i] != '\0') {
		if (ch[i] >= '0' && ch[i] <= '9')
			stack.push(ch[i]);
		else {
			op = ch[i];
			switch (op)
				case '+': {
				sum += (int)stack.top()-'0';
				stack.pop();
				sum += (int)stack.top()-'0';
				stack.pop();
			}
		}
		i++;
	}
	printf("%d", sum);
/*
	while (!stack.empty()) {
		cout << ' ' << stack.top();
		stack.pop();
	}
	*/


}