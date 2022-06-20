#include <stdio.h>

int main(void)
{
    char m[2][50];

    for (int i = 0; i < 2; i++)
    {
        scanf(" %[^\n]", m[i]);
    }
    for (int i = 0; i < 2; i++)
    {
        printf(" %s\n", m[i]);
    }
}