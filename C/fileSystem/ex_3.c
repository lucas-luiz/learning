#include <stdio.h>

int main()
{
    int i;
    char command;
    char content[20];
    FILE *stream;

    scanf(" %c", &command);
    while (command != 'e')
    {
        switch (command)
        {
        case 'a':
            // append
            stream = fopen("ex_3.dat", "a");
            scanf(" %s", content);
            fprintf(stream, "%s\n", content);
            fclose(stream);
            break;
        case 'r':
            // read
            stream = fopen("ex_3.dat", "r");
            if (stream == NULL)
            {
                printf("nothing to read");
            }
            else
            {
                i = 1;
                fscanf(stream, "%s", content);
                while (!feof(stream))
                {
                    printf("line %d - %s\n", i++, content);
                    fscanf(stream, "%s", content);
                }
            }
            fclose(stream);
            break;
        case 'w':
            // write
            stream = fopen("ex_3.dat", "w");
            scanf(" %s", content);
            fprintf(stream, "%s\n", content);
            fclose(stream);
            break;
        default:
            printf("ERROR\n");
            break;
        }
        scanf(" %c", &command);
    }
    return 0;
}