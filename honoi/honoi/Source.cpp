#include<stdio.h>

void hanoi(int num, char start, char temp, char end) {

    if (num > 0) {




        hanoi(num - 1, start, end, temp);

        printf("%d  %c -> %c  \n", num, start, end); /* 顯示移動狀況 */

        hanoi(num - 1, temp, start, end);

    }

}

int main() {

    hanoi(3, 'A', 'B', 'C');    /*四個盤子，以A為起始柱，以C為目標柱，以B為暫存柱*/

    return 0;

}

