#include <stdio.h>
float avrg(int a, int b, int c, char type)
{
    switch (type)
    {
    case 'A':
        return ((a + b + c) / 3);
    case 'P':
        return (((a * 5.0) + (b * 3.0) + (c * 2.0)) / 10);
    }
}
int main()
{
    printf("%f", avrg(1, 2, 3, 'P'));
}