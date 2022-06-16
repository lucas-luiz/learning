#include <stdio.h>
#include <string.h>
/*
Write a C function that reads a list of strings from the keyboard until the
string “Finished” is typed and returns the number of strings typed.
 */
int main(void)
{
    char array[10][50], arrayLen, i;
    for (i = 0; i < 10; i++)
    {
        scanf(" %[^\n]", array[i]);
        if (strcmp(array[i], "finished") == 0)
        {
            break;
        }
    }
    arrayLen = i;
    for (i = 0; i < arrayLen; i++)
    {
        printf(" \n%s", array[i]);
    }
}