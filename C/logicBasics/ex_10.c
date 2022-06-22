#include <stdio.h>

int op(int a, int b, char c)
{
    switch (c)
    {
    case 'S':
        return (a + b);
    case 'P':
        return (a * b);
    case 'D':
        return (a / b);
    }
}

int main()
{
    printf("%i", op(10, 5, 'D'));
    return 0;
}