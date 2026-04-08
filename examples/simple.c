#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printNumber(int n);
void main(void);

void printNumber(int n) {
    printf("%d\n", n);
}

void main(void) {
    int num = 42;
    printNumber(num);
}
