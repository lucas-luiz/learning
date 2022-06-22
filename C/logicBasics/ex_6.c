#include <stdio.h>

float intervalSum(float a, float b)
{
    // 1,2,3
    // (1+3)/2*3 = 6
    // (a+b)/2*(a-b)
    return (((a + b) / 2) * (b - a + 1));
}

int main()
{
    printf(" %f", intervalSum(1, 4)); // 10
    return 0;
}