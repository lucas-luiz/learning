#include <stdio.h>
#include <string.h>

int main()
{

    int i, k = 5, trocou = 0;
    char array[5][20], aux[20];

    for (i = 0; i < 5; i++)
    {
        scanf(" %[^\n]", array[i]);
    }

    for (i = 0; i < 5; i++) // bubble sort
    {
        if (strcmp(array[i], array[i++]) > 0)
        {
            strcpy(aux, array[i++]);
            strcpy(array[i++], array[i]);
            strcpy(array[i], aux);
        }
    }
    for (i = 0; i < 5; i++)
    {
        printf(" %s", array[i]);
    }

    return 0;
}