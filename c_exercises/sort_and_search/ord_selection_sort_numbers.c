/*
Insertion Sort
Algorítimo organiza um vetor de números, sempre selecionando o menor elemento do vetor e trocando
sua posição do primeiro elemento, no próximo ciclo ele incrementa em uma unidade o index inicial para
a estrutura de repetição
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define TAM 10 //tamanho do vetor 


//realiza troca entre dois elementos usados como parametros da função
void trocaElementos(int *a, int *b) 
{
    int aux = *a;
    *a = *b;
    *b = aux;
}
//retorna a posição do menor elemento ainda não ordenado
int menorElemento(int vetor[], int tamVetor, int primeiraPosicao) 
{
    int i, posicaoMenor = primeiraPosicao;
    for (i = primeiraPosicao + 1; i < tamVetor; i++) {
        if (vetor[i] < vetor[posicaoMenor])
        posicaoMenor = i;
    }
    return posicaoMenor;
}

//ordena o vetor por inserção
int ordenarSelectionSort(int vetor[], int tamVetor) 
{
    int i, posicaoMenor;
    for (i = 0; i < tamVetor; i++) 
    {
    posicaoMenor = menorElemento(vetor, tamVetor, i);
    trocaElementos(&vetor[i], &vetor[posicaoMenor]);
    }
}


int main()
{
int vetor[] = {2,5,7,9,10,8,4,3,1,6};

printf("Vetor desordenado: ");
int i;
for (i = 0; i < TAM; i++) 
{
    printf("%d",vetor[i]);
    if(i < TAM-1) 
    {
        printf(",");
    } else {
        printf("\n");
    }
}

ordenarSelectionSort(vetor, TAM);

printf("Vetor ordenado: ");
for (i = 0; i < TAM; i++) 
{
    printf("%d",vetor[i]);
    if(i < TAM-1) 
    {
        printf(",");
    } else {
        printf("\n");
    }
}

return 0;
}