#include <stdio.h>
#include <string.h>

/*
Write a C program that takes a string of maximum length 100 and
returns 1 if this string is a palindrome and zero otherwise. A word is said to be
palindrome if the sequence of its characters from left to right is equal to the sequence
of your characters from right to left. eg: arara
 */
int main()
{
    int stringLen, i;
    char string[10];
    scanf(" %[^\n]", string);

    stringLen = strlen(string);
    for (i = 0; i < stringLen; i++)
    {
        if (string[i] != string[stringLen - i - 1])
        {
            printf("This word is not a palindrome");
            return 0;
        }
    }
    printf("This word is a palindrome");
    return 0;
}