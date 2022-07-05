#include<stdio.h>

int main()
{

    int quantNotas, notas[50], media=6;
    
    printf("Insira a quantidade de notas");
    scanf("%d", &quantNotas);
    
    for(int i=0; i<quantNotas; i++){
        printf("\nnota %d :", i);
        scanf("%d", &notas[i]);
    }
    
    printf("notas maiores que a media:\n");
    for(int i=0; i<quantNotas; i++){
        if(notas[i]>media){
            printf("\nnota %d : %d", i, notas[i]);  
        }
    }
    return 0;
}