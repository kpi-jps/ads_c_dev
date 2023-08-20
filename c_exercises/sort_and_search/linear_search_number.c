/*
Implementação do algorítimo de busca linear
- Preenche um vetor de 1000 posições com os valores de 1 a 1000 em ordem.
- Faça a busca linear buscando cada um dos 1000 números, contando quantas
comparações foram feitas em cada busca e armazenando o total em uma variável e
imprima o total de comparações.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define TAM 1000 //tamanho do vetor de números

//Cria um vetor de "tam" posições e o preenche com número de 0 a "tam"
void criaVetor(int v[], int tam) 
{
    int i, num = 1;
    for (i = 0; i < tam; i++) 
    {
        v[i] = num;
        num++;
    }
}

//Busca um número em um vetor, retornando o índice da chave no vetor se a busca for bem sucedida,
//ou retornando -1 se a chave não foi encontrada.Recebe como parâmetro o vetor, seu tamanho e a 
//chave de busca
int buscaLinear(int v[], int tam, int numChave) 
{
    int i;
    for (i = 0; i < tam; i++) 
    {
        if(v[i] == numChave) 
        {
            return i;
        }
    }
    return -1;
}

int main() 
{
    int vetor[TAM];
    criaVetor(vetor, TAM);
    int t; //conta o total de interações nas buscas
    int c; //conta a quantidade de v
    int i;
    for (i = 0; i < TAM; i++)
    {
        c = buscaLinear(vetor, TAM, vetor[i]) + 1; //aqui adiciona 1 pois o índice que é retornado inicia em 0
        printf("Foram realizada(s) %d busca(s) para encontrar o %d.\n", c, vetor[i]);
        t += c;
    }
    printf("Total de %d interações.\n", t);
    return 0;
}