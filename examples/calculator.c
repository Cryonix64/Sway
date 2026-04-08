#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
void main(void);

int add(int a, int b) {
    return (a + b);
}

int subtract(int a, int b) {
    return (a - b);
}

int multiply(int a, int b) {
    return (a * b);
}

int divide(int a, int b) {
    if ((b == 0)) {
        return 0;
    }
    return (a / b);
}

void main(void) {
    int x = 15;
    int y = 3;
    printf("%d\n", add(x, y));
    printf("%d\n", subtract(x, y));
    printf("%d\n", multiply(x, y));
    printf("%d\n", divide(x, y));
}
