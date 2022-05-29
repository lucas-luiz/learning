#include <stdio.h>

int main()
{
    int codigos[5], valores[5], maiorValor, posMaiorValor;
    for (int i = 0; i < 5; i++)
    {
        printf("código: ");
        scanf("%d", &codigos[i]);
        printf("valor: ");
        scanf("%d", &valores[i]);
    }

    maiorValor = 0;
    for (int i = 0; i < 5; i++)
    {
        if (valores[i] > maiorValor)
        {
            maiorValor = valores[i];
            posMaiorValor = i;
        }
    }
    printf("O produto de maior valor: %d \nValor: %d", codigos[posMaiorValor], maiorValor);

    return 0;
}