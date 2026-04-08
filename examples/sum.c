#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int n);
void main(void);

int sum(int n) {
    int total = 0;
    int i = 1;
    while ((i <= n)) {
        (total = (total + i));
        (i = (i + 1));
    }
    return total;
}

void main(void) {
    printf("%d\n", sum(10));
}
