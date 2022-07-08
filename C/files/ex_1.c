#include <stdio.h>

int main()
{
    FILE *arq;
    if (fopen("ex_1", "w") == NULL)
    {
        printf("ERROR");
        return 0;
    }
    arq = fopen("ex_1", "w");
    putc('a', arq);
    fclose(arq);
    return 0;
}