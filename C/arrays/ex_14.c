#include <stdio.h>
struct aluno
{
    int mat;
    float rend;
}; // só o molde sem alocação de memória

int main()
{
    struct aluno a;
    scanf(" %d %f", &a.mat, &a.rend);
    printf("%d, %f", a.mat, a.rend);
    
    return 0;
}