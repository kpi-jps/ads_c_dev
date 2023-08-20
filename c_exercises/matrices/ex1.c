/******************************************************************************

Ex1. Uma matriz M pode ser transposta em uma matriz N onde o número de
linhas/colunas da primeira passa a ser o número de colunas/linhas da segunda.
Faça um programa que:
- Leia uma matriz M (o usuário deve fornecer a quantidade de linhas e a
quantidade de colunas que não deverão exceder 50 linhas e 50 colunas).
- Calcule a transposta N da matriz M.
- Imprima a transposta calculada.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int l, c; //l = linhas e c = colunas
    int i, j; //contadores

    float M[50][50], N[50][50]; //quantidade máxima de linhas e colunas é 50
    printf("Entre com número de linhas para a Matriz M: ");
    scanf("%i", &l);
    printf("Entre com número de colunas para a Matriz M: ");
    scanf("%i", &c);
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("Entre com o valor para a(%i, %i): ", i+1, j+1);
            scanf("%f", &M[i][j]);
        }
    }
    printf("Matriz M: \n");
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%.2f ", M[i][j]);
        }
        printf("\n");
    }
    //fazendo a transposta
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            N[j][i] = M[i][j];
        }
    }
    
    //imprimindo a transposta 
    //aqui inverte c com l, assim i < c e j < l
    printf("Matriz N (transposta de M): \n");
    for (i = 0; i < c; i++)
    {
        for (j = 0; j < l; j++)
        {
            printf("%.2f ", N[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

