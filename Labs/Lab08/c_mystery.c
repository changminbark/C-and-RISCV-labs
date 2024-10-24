#include <stdio.h>

int unused = 0xFEEDBEEF;
int x = 89;

int main() {
    x = 0;
    for (int i = 0; i < 11; i++) {
        x += i;
    }
    printf("%d\n", unused);
    printf("%d\n", x);

    return x;
}
