/*
Quick Sort
Algorítimo organiza um vetor de caracteres recursivamente, particionando o vetor inicial e depois 
os subvetores sempre em dois outros subvetores, um com elementos maiores e o outro com elementos
menores que o valor determinado como pivo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define TAMSTR 100
#define TAM 10
//realiza troca entre dois elementos usados como parametros da função
void trocaElementos(char a[], char b[]) 
{
    char aux[TAMSTR];
    strcpy(aux,a);
    strcpy(a,b);
    strcpy(b,aux);
}

//particiona o vetor em dois outros subvetores, um com valores maiores e outro com valores
//menores que um valor determinado como pivo
int particionarVetor(char vetor[][TAMSTR], int inicio, int fim) {
    //elemento pivo
    //por definição seleciona-se o ultimo valor do vetor
    char strPivo[TAMSTR];
    strcpy(strPivo, vetor[fim]);
    while (inicio < fim) 
    {
        while (inicio < fim && strcmp(vetor[inicio], strPivo) <= 0) 
        {
            inicio++;
        }
        while (inicio < fim && strcmp(vetor[fim], strPivo) > 0)  
        {
            fim--;
        }
        trocaElementos(vetor[inicio], vetor[fim]);
    }
    return inicio;
}

//ordena o vetor recursivamente
void ordenarQuickSort(char vetor[][TAMSTR], int inicio, int fim) 
{
    int pos;
    if (inicio < fim) {
        pos = particionarVetor(vetor, inicio, fim);
        ordenarQuickSort(vetor, inicio, pos-1);
        ordenarQuickSort(vetor, pos, fim);
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
        } else {
            printf("\n");
        }
    }

    ordenarQuickSort(vetor, 0, TAM-1);

    printf("Vetor ordenado: ");
    for (i = 0; i < TAM; i++) 
    {
        printf("%s",vetor[i]);
        if(i < TAM-1) 
        {
            printf(",");
        } else {
            printf("\n");
        }
    }
    return 0;
}