/*
Insertion Sort
Algorítimo organiza um vetor de strings, inserindo os elementos em suas posições corretas 
sem utilizar um vetor auxiliar. Algorítimo considera que o primeiro elemento já esta ordenado, ou seja,
esse não é movimentado
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define TAMSTR 100 //tamanho das strings no vetor.
#define TAM 10 //quantidade de strings no vetor.

//retorna a posição do elemento a ser inserido strcmp(vetor[i], vetor[j]) <= 0
int posicaoElemento(char vetor[][TAMSTR], int ultimaPosicao, char elemento[TAMSTR]) 
{
    int i;
    for (i = 0; i <= ultimaPosicao && strcmp(vetor[i], elemento) <= 0; i++); //é posível usar o for assim
    return i; 
}


//desloca o subvetor para inserir um elemento na posição correta
void deslocarSubvetor(char vetor[][TAMSTR], int primeiraPosicacao, int ultimaPosicao) 
{
    int i;
    for (i = ultimaPosicao; i >= primeiraPosicacao; i--) 
    {
        strcpy(vetor[i+1], vetor[i]);
    }
}


//ordena o vetor por inserção
int ordenarInsertioSort(char vetor[][TAMSTR], int tamVetor) 
{
    int i, posicao;
    char elemento[TAMSTR];
    //i começa em 1 pois considera-se que o primeiro elemento já está ordenado
    for (i = 1; i < tamVetor; i++) {
        strcpy(elemento, vetor[i]);
        posicao = posicaoElemento(vetor, i-1, elemento);
        deslocarSubvetor(vetor, posicao, i-1);
        strcpy(vetor[posicao], elemento);
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

    ordenarInsertioSort(vetor,TAM);

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