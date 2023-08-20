/*
Teste algorítimo de busca linear: Neste caso a função irá preencher um vetor com os
índices dos elementos encontrado no vetor onde a busca é feita, de acordo com o valor da chave
de busca. Além disso a função retorna o a quantidade de valores preenchidos no vetor onde estão 
os índices.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define TAM 10 //tamanho do vetor de números


int buscaLinear(int v[], int tam, int numChave, int enc[]) 
{
    int i;
    int j = 0;
    for (i = 0; i < tam; i++) 
    {
        if(v[i] == numChave) 
        {
            enc[j] = i;
            j++;
        }
    }
    return j;
}

int main() 
{
    int vetor[] = {2,5,8,9,10,8,8,3,1,6};
    int encontrados[TAM]; //vetor com os índices onde os valores iguais a chave estão localizados no vetor
    int i, j;
    j = buscaLinear(vetor, TAM, 8, encontrados);
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