#include <stdio.h>
int main()
{
    int a[5], b[5], j = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("\na[%d]: ", i);
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        if (a[i] % 2 == 0)
        {
            b[j] = a[i];
            j++;
        }
    }
    for (int i = 0; i < j; i++)
    {
        printf("\npar: %d", b[i]);
    }

    return 0;
}