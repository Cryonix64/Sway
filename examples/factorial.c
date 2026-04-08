#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorial(int n);
void main(void);

int factorial(int n) {
    if ((n <= 1)) {
        return 1;
    } else {
        return (n * factorial((n - 1)));
    }
}

void main(void) {
    int result = factorial(5);
    printf("%d\n", result);
}
