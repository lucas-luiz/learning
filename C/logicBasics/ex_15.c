#include <stdio.h>

void sort(int a, int b, int c)
{
    if (a < b && a < c)
    {
        printf("%d, ", a);
        if (b < c)
        {
            printf("%d, %d", b, c);
        }
        else
        {
            printf("%d, %d", c, b);
        }
    }
    else if (b < a && b < c)
    {
        printf("%d, ", b);
        if (a < c)
        {
            printf("%d, %d", a, c);
        }
        else
        {
            printf("%d, %d", c, a);
        }
    }
    else
    {
        printf("%d, ", c);
        if (a < b)
        {
            printf("%d, %d", a, b);
        }
        else
        {
            printf("%d, %d", b, a);
        }
    }
}

int main()
{
    int a = 9, b = 5, c = 3;
    sort(a, b, c);
    return 0;
}