#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100


void inicia_grafo(int grafo[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for(int j = 0; j < TAM; j++) 
            grafo[i][j] = 0;
}

void insere_aresta(int grafo[TAM][TAM], int i, int j) {
    grafo[i][j] = 1;
    grafo[j][i] = 1;
}

