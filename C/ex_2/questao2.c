#include <stdio.h>

int main()
{
    int n, i, fat = 1;
    printf("Insira o valor de N: ");
    scanf("%i", &n);
    for (i = 2; i <= n; i++)
    {
        fat = fat * i;
    }
    printf("%i! = %i", n, fat);
    return 0;
}
