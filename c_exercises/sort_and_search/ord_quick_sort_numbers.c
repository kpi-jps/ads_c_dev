/*
Quick Sort
Algorítimo organiza um vetor de números recursivamente, particionando o vetor inicial e depois 
os subvetores sempre em dois outros subvetores, um com elementos maiores e o outro com elementos
menores que o valor determinado como pivo
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define TAM 10
//realiza troca entre dois elementos usados como parametros da função
void trocaElementos(int *a, int *b) 
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

//particiona o vetor em dois outros subvetores, um com valores maiores e outro com valores
//menores que um valor determinado como pivo
int particionarVetor(int vetor[], int inicio, int fim) 
{
    //elemento pivo
    //por definição seleciona-se o ultimo valor do vetor
    int pivo = vetor[fim];
    while (inicio < fim) 
    {
        while (inicio < fim && vetor[inicio] <= pivo) 
        {
            inicio++;
        }
        while (inicio < fim && vetor[fim] > pivo ) 
        {
            fim--;
        }
        trocaElementos(&vetor[inicio], &vetor[fim]);
    }
    return inicio;
}

//ordena o vetor recursivamente
void ordenarQuickSort(int vetor[], int inicio, int fim) 
{
    int pos;
    if (inicio < fim) 
    {
        pos = particionarVetor(vetor, inicio, fim);
        ordenarQuickSort(vetor, inicio, pos -1);
        ordenarQuickSort(vetor, pos, fim);
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

ordenarQuickSort(vetor, 0, TAM-1);

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