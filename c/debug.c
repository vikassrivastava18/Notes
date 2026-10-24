// Become familiar wih C syntax
// Learn to debug buggy code

#include <stdio.h>

int main(void)
{
    // Ask for your name and where live
    char name[50];
    char location[50];

    printf("Enter your name: ");
    scanf(" %49[^\n]", name);

    printf("Enter location: ");
    scanf(" %49[^\n]", location);

    // Say hello
    printf("Hello, %s, from %s!\n", name, location);
}
