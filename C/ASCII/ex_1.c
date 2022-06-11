
/* Write a C program that reads 3 strings of maximum length 50,
and the prints to the screen in alphabetical order.
You can use strcmp function from string.h library */
#include <stdio.h>
readArray(address, length)
{
    char *pointer;
    char string[length];
    pointer = address;

    scanf(" %s", pointer);
    printf("%s\n", *pointer);
    return string;
}
int main(void)
{
    int ASCII_A = 65, ASCII_a = 97;
    char a[50], b[50], c[50];
    readArray(&a, 50);
    /* readArray(b, 50);
    c[50]; */
}