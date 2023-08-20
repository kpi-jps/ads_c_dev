/*
Teste algorítimo de busca binária: Neste caso a função irá preencher um vetor com os
índices dos elementos encontrado no vetor onde a busca é feita, de acordo com o valor da chave
de busca. Além disso a função retorna o a quantidade de valores preenchidos no vetor onde estão 
os índices.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define TAM 10 //tamanho do vetor de números


int buscaBinaria(int v[], int tam, int numChave, int enc[]) 
{
    int ini = 0;
    int fim = tam - 1;
    int meio;
    int j = 0;
    while (ini <= fim)
    {
        meio = (ini + fim) / 2;
        if (v[meio] == numChave) 
        {
            enc[j] = meio;
            j++;
            ini = meio+1;

        } else if (numChave < v[meio]) 
        {
            fim = meio-1;
        } else 
        {
            ini = meio+1;
        }
    }
    return j;
}

int main() 
{
    int vetor[] = {0,1,2,3,4,5,6,8,8,9};
    int encontrados[TAM]; //vetor com os índices onde os valores iguais a chave estão localizados no vetor
    int i, j;
    j = buscaBinaria(vetor, TAM, 8, encontrados);
    printf("encontrados em vetor no(s) índice(s): ");
    for (i = 0; i < j; i++) 
    {
        printf("%d",encontrados[i]);
        if(i < j-1) 
        {
            printf(",");
        } else {
            printf("\n");
        }
}
    return 0;
}