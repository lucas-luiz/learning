/* Write a program that reads from the keyboard two vectors of integers of size = 5 and
fill in a third vector that should contain only the numbers that are in the two
vectors. The program should print the number of elements inserted in the third
vector */
#include <stdio.h>
int main()
{
    int a[5], b[5], c[5], i, j, k, cIndex = 0;

    for (i = 0; i < 5; i++)
    {
        scanf(" %d%d", &a[i], &b[i]);
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (a[i] == b[j])
            {
                c[cIndex] = a[i];
                cIndex++;
                break;
            }
        }
    }

    for (i = 0; i < cIndex; i++)
    {
        printf("%d", c[i]);
    }

    return 0;
}