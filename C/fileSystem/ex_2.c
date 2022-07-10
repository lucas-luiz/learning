#include <stdio.h>
int main()
{
    int mat, i;
    float nota1, nota2;
    FILE *arq; // cria um ponteiro para um arquivo
    /* abre o arquivo exercicioArquivo no modo leitura e gravação e atribui o endereço do arquivo ao
   ponteiro arq. O modo w+ abre o arquivo no inicio substituindo o conteúdo do arquivo.*/
    arq = fopen("ex_2.dat", "w+"); // se o arquivo não existir, o arquivo será criado
    if (arq == NULL)
    { // se não foi possível abrir o arquivo, arq será NULL
        printf("\nArquivo inválido");
        return 1; // interrompe o programa retornando um valor diferente de 0
    }
    else
    { // Caso contrário, os dados serão solicitados ao usuário
        printf("\nDigite a mat:");
        scanf("%d", &mat);
        while (mat != 0)
        {
            printf("\nDigite a N1:");
            scanf("%f", &nota1);
            printf("\nDigite a N2:");
            scanf("%f", &nota2);
            fprintf(arq, "%d %.2f %.2f\n", mat, nota1, nota2); // grava os valores das variáveis nota1 e nota2 no arquivo apontado por arq
                                                               // o formato %.2f no fprintf salva somente duas casas decimais no arquivo
            printf("\nDigite a mat:");
            scanf("%d", &mat);
        }
        i = 1;
        rewind(arq);                                   // volta para o início do arquivo
        fscanf(arq, "%d %f %f", &mat, &nota1, &nota2); // lê a primeira linha do arquivo
        // o laço abaixo é executado enquanto não estiver no final do arquivo apontado por arq
        while (!feof(arq))
        {
            printf("\nMatricula do aluno %d: %d - Nota1: %.2f/Nota2: %.2f", i++, mat, nota1, nota2);
            fscanf(arq, "%d %f %f", &mat, &nota1, &nota2); // le as demais informações do arquivo
        }
    }
    printf("\n");
    fclose(arq); // fecha o arquivo
}