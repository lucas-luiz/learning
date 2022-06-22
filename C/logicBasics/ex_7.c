#include <stdio.h>

int sort(int a, int b)
{
    if (a > b)
    {
        printf("%d, ", b);
        printf("%d", a);
    }
    else
    {
        printf("%d, ", a);
        printf("%d", b);
    }
}
int main()
{
    sort(6, 2);
    return 0;
}