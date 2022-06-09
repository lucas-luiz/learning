/* Write a program that reads two square matrices A and B (3x3) and writes the matrix
C, resulting from the multiplication between A and B. Print C */
#include <stdio.h>
int main()
{
    int a[3][3], b[3][3], c[3][3], i, j, k, count = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" A[%d][%d]: ", i, j);
            scanf(" %d", &a[i][j]);
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" A[%d][%d]: ", i, j);
            scanf(" %d", &b[i][j]);
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                count = count + (a[i][k] * b[k][j]);
            }
            c[i][j] = count;
            count = 0;
        }
    }
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%d ", c[i][j]);
        }
    }
    return 0;
}