#include <stdio.h>

float idealWeight(float alt, char sex)
{
    switch (sex)
    {
    case 'M':
        return ((72.7 * alt) - 58);
    case 'F':
        return ((62.1 * alt) - 44.7);
    }
    return 0;
}
int main()
{
    float alt;
    char sex;

    scanf(" %f %c", &alt, &sex);
    while (alt > 0.0)
    {
        printf("Ideal weight: %f\n", idealWeight(alt, sex));
        scanf(" %f %c", &alt, &sex);
    }
}