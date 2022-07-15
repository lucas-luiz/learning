#include <stdio.h>
#include <string.h>
typedef struct
{
    char name[10];
    int cod;
} Product;

void defineProducts(Product p[], int size)
{
    int i;
    // ler produtos[]
    for (i = 0; i < size; i++)
    {
        scanf(" %s", p[i].name);
        p[i].cod = i;
    }
    printf("products defined\n");
    return;
}
void storeProducts(Product p[], int size)
{
    FILE *arq;
    arq = fopen("ex_4.dat", "w");

    int i;
    for (i = 0; i < size; i++)
    {
        fprintf(arq, "%s %d", p[i].name, p[i].cod);
    }
    fclose(arq);
    printf("products stored\n");
    return;
}
void readProducts(Product p[], int size)
{
    int i;
    FILE *arq;
    arq = fopen("ex_4.dat", "r");

    for (i = 0; i < size + 1; i++)
    {

        if (!feof(arq))
        {
            fscanf(arq, " %s %d", p[i].name, &p[i].cod);
            printf("line %d - %s %d\n", i, p[i].name, p[i].cod);
        }
    }
    printf("products readed\n");
}
void updateProduct(int size, char name[], char newName[])
{
    int i;
    FILE *arq;
    arq = fopen("ex_4.dat", "r");
    Product produtos[size];
    for (i = 0; i < size; i++)
    {
        if (!feof(arq))
        {
            fscanf(arq, " %s %d", produtos[i].name, &produtos[i].cod);
            if (strcmp(produtos[i].name, name) == 0)
            {

                strcpy(produtos[i].name, newName);
                printf("updated: %d - %s to %s", i, name, produtos[i].name);
            }
        }
    }
    storeProducts(produtos, size);
    readProducts(produtos, size);
    printf("products updated");
    fclose(arq);
    return;
}

int main()
{
    int i, size = 4;
    // CREATE DATA
    Product produtos[size];
    defineProducts(produtos, size);
    // STORE DATA IN THE FILE
    storeProducts(produtos, size);
    // GET DATA FROM THE FILE
    readProducts(produtos, size);
    // UPDATE CERTAIN DATA IN THE FILE
    updateProduct(size, "lucas", "giovanna");

    return 0;
}