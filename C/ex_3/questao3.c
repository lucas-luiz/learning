#include <stdio.h>

int main()
{
    int num = 1, den;
    float res = 0;
    for (den = 1; den <= 50; den++)
    {
        res = res + (num / den);
        num = num + 2;
    }
    printf("RESULTADO: %.2f", res);
}
