#include <stdio.h>
#include <string.h>
struct aluno
{
    int mat;
    float rend;
    int cod;
    char nome[100];
}; // só o molde sem alocação de memória

int main()
{
    char newNome[100];
    struct aluno a;
    scanf(" %d %f %d %[^\n]", &a.mat, &a.rend, &a.cod, a.nome);
    printf("%d, %f, %d, %s", a.mat, a.rend, a.cod, a.nome);

    printf("\nconfirmar nome: ");
    scanf(" %[^\n]", newNome);
    if (strcmp(newNome, a.nome) == 0)
    {
        printf("\nalterar matricula: ");
        scanf(" %d", &a.mat);
        printf("%d, %f, %d, %s", a.mat, a.rend, a.cod, a.nome);
    }
    else
    {
        printf("\nNome do aluno nao encontrado");
    }
    return 0;
}