/*
Implementação do algorítimo de busca linear
- Preenche um vetor de 1000 posições com os valores de 1 a 1000 em ordem.
- Faça a busca binária buscando cada um dos 1000 números, contando quantas
comparações foram feitas em cada busca e armazenando o total em uma variável e
imprima o total de comparações.
Obs: Para utilizar este tipo de busca o vetor precisa estar ordenado
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
//ou retornando -1 se a chave não foi encontrada. Recebe como parâmetro o vetor, seu tamanho e a 
//chave de busca
int buscaBinaria(int v[], int tam, int numChave) 
{
    int ini = 0;
    int fim = tam - 1;
    int meio;
    while (ini <= fim)
    {
        meio = (ini + fim) / 2;
        if (v[meio] == numChave) 
        {
            return meio;
        } else if (numChave < v[meio]) 
        {
            fim = meio-1;
        } else 
        {
            ini = meio+1;
        }
    }
    return -1;
}
//nesta função adptada será retornado o quantidade de interação necessária
//para encontrar a chave
int buscaBinariaAdaptada(int v[], int tam, int numChave) 
{
    int ini = 0;
    int fim = tam - 1;
    int meio;
    int cont = 0;
    while (ini <= fim)
    {
        meio = (ini + fim) / 2;
        if (v[meio] == numChave) 
        {
            //return meio;
            return cont;
        } else if (numChave < v[meio]) 
        {
            fim = meio-1;
        } else 
        {
            ini = meio+1;
        }
        cont++;
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
        c = buscaBinariaAdaptada(vetor, TAM, vetor[i]); 
        printf("Foram realizada(s) %d busca(s) para encontrar o %d.\n", c, vetor[i]);
        t += c;
    }
    printf("Total de %d interações.\n", t);
    return 0;
}