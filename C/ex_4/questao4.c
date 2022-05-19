#include <stdio.h>

int main()
{
    int lim_inf, lim_sup, i, soma = 0;
    printf("insira o limite inferior do intervalo: ");
    scanf("%i", &lim_inf);
    printf("insira o limite inferior do intervalo: ");
    scanf("%i", &lim_sup);

    printf("NUMEROS PARES DO INTERVALO ABERTO\n");
    for (i = lim_inf + 1; i < lim_sup; i++)
    {
        if (i % 2 == 0)
        {
            printf("%i\n", i);
            soma = soma + i;
        }
    }
    printf("SOMATORIA DOS NUMEROS = %i", soma);
}
