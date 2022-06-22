#include <stdio.h>
float volume(int r)
{
    return ((4 * 3.1415 * r * r * r) / 3);
}
int main()
{
    printf("%f", volume(1));
    return 0;
}