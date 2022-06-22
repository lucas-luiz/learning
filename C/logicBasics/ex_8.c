#include <stdio.h>

void info()
{
    printf("Curso Ciencia da Computacao\nDisciplina Fundamentos de Programacao\nUniversidade Federal de Itajuba");
}
char conecpt(int average)
{
    if (average >= 0 && average < 5)
    {
        return 'R';
    }
    else if (average >= 5 && average < 7)
    {
        return 'E';
    }
    else
    {
        return 'A';
    }
}
int main()
{
    info();
    printf("\n%c", conecpt(6));
    return 0;
}