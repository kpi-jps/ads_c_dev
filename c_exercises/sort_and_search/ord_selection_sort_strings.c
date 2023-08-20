/*
Insertion Sort
Algorítimo organiza um vetor de caracteres (string), sempre selecionando o menor elemento do vetor e trocando
sua posição do primeiro elemento, no próximo ciclo ele incrementa em uma unidade o index inicial para
a estrutura de repetição
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define TAMSTR 100 //tamanho string
#define TAM 10 //tamanho do vetor 


//realiza troca entre dois elementos usados como parametros da função
void trocaElementos(char a[], char b[]) 
{
    char aux[TAMSTR];
    strcpy(aux,a);
    strcpy(a,b);
    strcpy(b,aux);
}

//retorna a posição do menor elemento ainda não ordenado
int menorElemento(char vetor[][TAMSTR], int tamVetor, int primeiraPosicao) 
{
    int i, posicaoMenor = primeiraPosicao;
    for (i = primeiraPosicao + 1; i < tamVetor; i++) {
        if (strcmp(vetor[i], vetor[posicaoMenor]) < 0)
        posicaoMenor = i;
    }
    return posicaoMenor;
}

//ordena o vetor por inserção
void ordenarSelectionSort(char vetor[][TAMSTR], int tamVetor) 
{
    int i, posicaoMenor;
    for (i = 0; i < tamVetor; i++) 
    {
    posicaoMenor = menorElemento(vetor, tamVetor, i);
    trocaElementos(vetor[i], vetor[posicaoMenor]);
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

    ordenarSelectionSort(vetor, TAM);

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