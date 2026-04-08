#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* greet(const char* name);
void main(void);

const char* greet(const char* name) {
    return "Hello, ";
}

void main(void) {
    int greeting = greet("World");
    printf("%d\n", greeting);
}
