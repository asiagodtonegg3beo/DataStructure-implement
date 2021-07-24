#include<stdio.h>

void hanoi(int num, char start, char temp, char end) {

    if (num > 0) {




        hanoi(num - 1, start, end, temp);

        printf("%d  %c -> %c  \n", num, start, end); /* ��ܲ��ʪ��p */

        hanoi(num - 1, temp, start, end);

    }

}

int main() {

    hanoi(3, 'A', 'B', 'C');    /*�|�ӽL�l�A�HA���_�l�W�A�HC���ؼЬW�A�HB���Ȧs�W*/

    return 0;

}

