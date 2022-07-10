#include <stdio.h>
#include <string.h>
typedef struct // redefine specific struct(new type) to Product
{
    int cod;
    float price;
} Product;

void verifyProduct(int productIndex, Product *products)
{
    printf(" %i", products[productIndex].cod);
}

int main()
{
    int i;
    Product products[5];
    for (i = 0; i < 2; i++)
    {
        scanf(" %d%f", &products[i].cod, &products[i].price);
    }
    verifyProduct(1, products);
    return 0;
}