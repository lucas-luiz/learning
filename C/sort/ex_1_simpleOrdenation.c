#include <stdio.h>
#include <stdbool.h>
#ifdef _WIN32 || _WIN64
#include <Windows.h>
#else
#include <unistd.h>
#endif

void printVector(int v[3])
{
    printf("\n Vetor: ");
    for (int i = 0; i < 3; i++)
    {
        printf("[%d] ", v[i]);
    }
}

int main()
{
    int v[3] = {3, 2, 1}, j = 0, aux;
    bool ok = true, trocou = false;

    printVector(v);
    while (j <= 3)
    {
        trocou = false;
        for (int i = j + 1; i < 3; i++)
        {

            if (v[j] > v[i])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                trocou = true;
#ifdef _WIN32 || _WIN64
                Sleep(2000);
#else
                sleep(2);
#endif
                printVector(v);
                break;
            }
        }
        if (trocou == false)
        {
            j++;
        }
    }

    return 0;
}