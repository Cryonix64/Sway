#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void);

void main(void) {
    int i = 0;
    while ((i < 5)) {
        printf("%d\n", i);
        (i = (i + 1));
    }
}
