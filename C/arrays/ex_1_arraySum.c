#include <stdio.h>
int main()
{
    int a[5], b[5], c[5];
    for (int i = 0; i < 5; i++)
    {
        printf("valor do vetor A, posicao %d: ", i);
        scanf("%d", &a[i]);
        printf("valor do vetor B, posicao %d: ", i);
        scanf("%d", &b[i]);
        c[i] = a[i] + b[i];
    }
    for (int i = 0; i < 5; i++)
        printf("\nSoma A+B na posicao %d: %d", i, c[i]);

    return 0;
}