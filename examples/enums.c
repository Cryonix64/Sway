#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void);

enum Color {
    Red,
    Green,
    Blue
};

void main(void) {
    Color myColor = Color.Red;
    printf("%d\n", myColor);
}
