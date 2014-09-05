#include <cs50.h>
#include <stdio.h>

int main(void) {
    printf("Name:\n");
    string name;
    name = GetString();
    printf("hello, %s\n", name );
}

