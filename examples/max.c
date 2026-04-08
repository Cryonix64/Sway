#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b);
int max3(int a, int b, int c);
void main(void);

int max(int a, int b) {
    if ((a > b)) {
        return a;
    }
    return b;
}

int max3(int a, int b, int c) {
    int m1 = max(a, b);
    return max(m1, c);
}

void main(void) {
    printf("%d\n", max3(5, 10, 8));
}
