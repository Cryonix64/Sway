#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void);

typedef struct {
    const char* name;
    int age;
} Person;

void main(void) {
    Person person = Person();
    printf("%d\n", person.name);
}
