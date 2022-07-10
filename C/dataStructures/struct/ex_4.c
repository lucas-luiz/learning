#include <stdio.h>
/*
Make a function that receives a vector of integer elements of dimension N (N = 50),
an integer element X and return a value that corresponds to the number of times the
element X appears in the vector. Write an algorithm that reads a matrix A of
integer elements of dimension M x N, (M,N = 50) and, using the subroutine above, generate
a vector V whose elements represent how many times the value zero (0) appears in
each row of matrix A. Write matrix A and vector V.
 */
int search(int x, int arr[])
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] == x)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int arr[5][5], i, j, searchArr[5];
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            scanf(" %i", &arr[i][j]);
        }
        searchArr[i] = search(0, arr[i]);
    }

    for (i = 0; i < 5; i++)
    {
        printf("[%d] ", searchArr[i]);
    }
    return 0;
}