/**
  * CSCI 306
  * lab 02 - primefact.c
  * compile with: make primefact
  * notes: python time was 3.367 s while c time was 0.078 s
  * result: the C program is 43.17 times faster than python
*/
#include <stdio.h>

int n = 2147483645;
int i = 2;

int main(void) {
    while (i <= n) {
        if (n % i == 0) {
            printf("%d\n", i);
            n = n / i;
        } else {
            i++;
        }
    }
    return 0;
}
