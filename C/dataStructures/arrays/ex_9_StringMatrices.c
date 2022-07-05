#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, j, k, count = 0;
    char phrases[2][50], keyWord[50], *t, aux[50];

    for (i = 0; i < 1; i++)
    {
        printf("phrase: ");

        scanf(" %[^\n]", phrases[i]);
    }
    printf("keyword: ");
    scanf(" %s", keyWord);

    t = strtok(phrases[0], " ");
    while (t != NULL)
    {
        if (strcmp(t, keyWord) == 0)
        {
            count++;
        }
        t = strtok(NULL, " ");
    }
    printf("the keyword appeared %d times", count);
}