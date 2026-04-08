#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibonacci(int n);
void main(void);

int fibonacci(int n) {
    if ((n <= 1)) {
        return n;
    }
    return (fibonacci((n - 1)) + fibonacci((n - 2)));
}

void main(void) {
    printf("%d\n", fibonacci(10));
}
