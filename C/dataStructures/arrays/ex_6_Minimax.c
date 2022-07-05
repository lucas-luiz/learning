#include <stdio.h>

int main()
{
    int d, greaterRow, greater, min;
    printf("Dimension: ");
    scanf("%d", &d);
    if (d > 10)
    {
        printf("dimension greater then 10");
        return 0;
    }
    int mat[d][d];

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            printf("\n[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    greater = mat[0][0];
    greaterRow = 0;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (greater < mat[i][j])
            {
                greater = mat[i][j];
                greaterRow = i;
            }
            printf("\n[%d][%d]: [%d]", i, j, mat[i][j]);
        }
    }

    min = mat[greaterRow][0];
    for (int j = 0; j < d; j++)
    {
        if (min > mat[greaterRow][j])
        {
            min = mat[greaterRow][j];
        }
    }
    printf("\nMINIMAX: %d", min);
    return 0;
}