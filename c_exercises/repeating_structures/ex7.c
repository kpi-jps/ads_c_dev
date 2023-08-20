/******************************************************************************
Ex. 7 Ler m e escrever m linhas com i asteriscos alinhadas pela
esquerda, onde i corresponde ao número da linha corrente.
Exemplo: Para m=6 a saída do programa deve ser 

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()

{
    int m, i, j;
    printf("Entre com um valor inteiro para m: ");
    scanf("%i", &m);
    for (i = 1; i <= m; i++) 
    {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}


