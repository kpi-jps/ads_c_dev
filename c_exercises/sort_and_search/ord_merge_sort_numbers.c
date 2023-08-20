/*
Merge Sort
Algorítimo organiza um vetor de números recursivamente, dividindo o vetor ao meio e intercalando os subvetores
 o vetor inicial utilizando um vetor auxiliar 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define TAM 10 //tamanho do vetor e do vetor auxiliar

//intercala os elementos do vetor a ser ordenado no vetor auxiliar
void intercalar(int vetor[], int inicio, int meio, int fim) {
    int auxiliar[TAM]; // vetor auxiliar
    int i = inicio, j = meio + 1, k = 0; // índices dos vetores
    // intercala
    while(i <= meio && j <= fim) 
    {
        if (vetor[i] <= vetor[j]) 
        {
            auxiliar[k] = vetor[i];
            k++;
            i++;
        }
        else 
        {
            auxiliar[k] = vetor[j];
            k++;
            j++;
        }  
    }
    // copia resto de cada subvetor
    while (i <= meio) 
    {
        auxiliar[k] = vetor[i];
        k++;
        i++;
    }
    while (j <= fim) 
    {
        auxiliar[k] = vetor[j];
        k++;
        j++;
    }
    // copia de auxiliar para vetor
    for (i = inicio, k = 0; i <= fim; i++, k++) 
    {
        vetor[i] = auxiliar[k];
    }  
}

//ordena o vetor recursivamente usando a intercalação
void ordenarMergeSort(int vetor[], int inicio, int fim) 
{
    int meio;
    if (inicio < fim) 
    {
        meio = (inicio + fim) / 2;
        ordenarMergeSort(vetor, inicio, meio);
        ordenarMergeSort(vetor, meio+1, fim);
        intercalar(vetor, inicio, meio, fim);
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

ordenarMergeSort(vetor, 0, TAM-1);

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