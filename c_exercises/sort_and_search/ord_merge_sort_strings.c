/*
Merge Sort
Algorítimo organiza um vetor de números recursivamente, dividindo o vetor ao meio e intercalando os subvetores
 o vetor inicial utilizando um vetor auxiliar 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define TAMSTR 100 //tamanho das strings do vetor e do vetor auxiliar
#define TAM 10 //quantidade de strings no vetor e vetor auxiliar

//intercala os elementos do vetor a ser ordenado no vetor auxiliar
void intercalar(char vetor[][TAMSTR], int inicio, int meio, int fim) {
    char auxiliar[TAM][TAMSTR]; // vetor auxiliar
    int i = inicio, j = meio + 1, k = 0; // índices dos vetores
    // intercala
    while(i <= meio && j <= fim) 
    {
        if (strcmp(vetor[i], vetor[j]) <= 0) 
        {
            strcpy(auxiliar[k], vetor[i]);
            k++;
            i++;
        }
        else 
        {
            strcpy(auxiliar[k], vetor[j]);
            k++;
            j++;
        }  
    }
    // copia resto de cada subvetor
    while (i <= meio) 
    {
        strcpy(auxiliar[k], vetor[i]);
        k++;
        i++;
    }
    while (j <= fim) 
    {
        strcpy(auxiliar[k], vetor[j]);
        k++;
        j++;
    }
    // copia de auxiliar para vetor
    for (i = inicio, k = 0; i <= fim; i++, k++) 
    {
        strcpy(vetor[i],auxiliar[k]);
    }  
}

//ordena o vetor recursivamente usando a intercalação
void ordenarMergeSort(char vetor[][TAMSTR], int inicio, int fim) 
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
    char vetor[TAM][TAMSTR];
    strcpy(vetor[0], "Joao");
    strcpy(vetor[1], "Pedro");
    strcpy(vetor[2], "Felipe");
    strcpy(vetor[3], "Lucas");
    strcpy(vetor[4], "Mateus");
    strcpy(vetor[5], "Judas");
    strcpy(vetor[6], "Tomé");
    strcpy(vetor[7], "Bartolomeu");
    strcpy(vetor[8], "Tiago");
    strcpy(vetor[9], "André");
    printf("Vetor desordenado: ");
    int i;
    for (i = 0; i < TAM; i++) 
    {
        printf("%s",vetor[i]);
        if(i < TAM-1) 
        {
            printf(",");
        } else 
        {
            printf("\n");
        }
    }

    ordenarMergeSort(vetor, 0, TAM-1);

    printf("Vetor ordenado: ");
    for (i = 0; i < TAM; i++) 
    {
        printf("%s",vetor[i]);
        if(i < TAM-1)
        {
            printf(",");
        } else 
        {
            printf("\n");
        }
    }
    return 0;
}