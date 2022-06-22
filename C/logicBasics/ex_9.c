#include <stdio.h>

void format(char *name)
{
    printf("\nC Training\nName: %30s, 2022", name);
}
int main()
{
    char name[30];
    scanf(" %[^\n]", name);
    format(name);
    return 0;
}