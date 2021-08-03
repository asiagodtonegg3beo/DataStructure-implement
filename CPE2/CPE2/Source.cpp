#include<stdio.h>
#include<iostream>
using namespace std;
int main() {
	char ch[30] = {0};
	int i=0;
	int sum = 0;
	int s=0;
	while (1) {
		cin >> ch;
		while (ch[i] != '\0') {
			switch (ch[i])
			{
			case '0':
				cout << '0';
				s++;
				break;
			case '1':
				cout << '1';
				s++;
				break;
			case 'A': case'B': case'C':
				cout << "2";
				break;

			case 'D': case'E': case'F':
				cout << "3";
				break;

			case 'G': case'H': case'I':
				cout << "4";
				break;

			case 'J': case'K': case'L':
				cout << "5";
				break;

			case 'M': case'N': case'O':
				cout << "6";
				break;

			case 'P': case'Q': case'R': case'S':
				cout << "7";
				break;
			case 'T': case'U': case'V':
				cout << "8";
				break;
			case 'W': case'X': case'Y': case'Z':
				cout << "9";
				break;
			case '-':
				cout << "-";
				sum++;
				s++;
				break;
			case '\0':
				break;
			default:
				break;
			}
			i++;
		}
		cout << " " << i - s << " " << sum <<endl;
		sum = 0;
		s = 0;
		i = 0;
	}



}