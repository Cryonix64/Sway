#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b);
void main(void);

int max(int a, int b) {
    if ((a > b)) {
        return a;
    } else {
        return b;
    }
}

void main(void) {
    int result = max(5, 10);
    printf("%d\n", result);
    int x = 15;
    if ((x > 10)) {
        printf("%d\n", 1);
    } else {
        if ((x == 10)) {
            printf("%d\n", 0);
        } else {
            printf("%d\n", (-1));
        }
    }
}
