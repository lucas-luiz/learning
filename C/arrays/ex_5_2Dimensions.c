#include <stdio.h>
int main()
{
    int r = 2, c = 3, greater;
    int mat[r][c];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("\n[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\n\nARRAY\n");
    greater = mat[0][0];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (greater < mat[i][j])
            {
                greater = mat[i][j];
            }
            printf("\n[%d][%d]: [%d]", i, j, mat[i][j]);
        }
    }
    printf("\ngreater: %d", greater);
    return 0;
}