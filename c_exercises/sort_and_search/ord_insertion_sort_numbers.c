/*
Insertion Sort
Algorítimo organiza um vetor de números, inserindo os elementos em suas posições corretas 
sem utilizar um vetor auxiliar. Algorítimo considera que o primeiro elemento já esta ordenado, ou seja,
esse não é movimentado
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define TAM 10 //tamanho do vetor 

//retorna a posição do elemento a ser inserido
int posicaoElemento(int vetor[], int ultimaPosicao, int elemento) 
{
    int i;
    for (i = 0; i <= ultimaPosicao && vetor[i] <= elemento; i++); //é posível usar o for assim
    return i;  
}


//desloca o subvetor para inserir um elemento na posição correta
void deslocarSubvetor(int vetor[], int primeiraPosicacao, int ultimaPosicao) 
{
    int i;
    for (i = ultimaPosicao; i >= primeiraPosicacao; i--) 
    {
        vetor[i+1] = vetor[i];
    }
}


//ordena o vetor por inserção
int ordenarInsertioSort(int vetor[], int tamVetor) 
{
    int i, posicao, elemento;
    //i começa em 1 pois considera-se que o primeiro elemento já está ordenado
    for (i = 1; i < tamVetor; i++) {
        elemento = vetor[i];
        posicao = posicaoElemento(vetor, i-1, elemento);
        deslocarSubvetor(vetor, posicao, i-1);
        vetor[posicao] = elemento;
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

ordenarInsertioSort(vetor, TAM);

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