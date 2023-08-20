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


char concatenaStrs(char str1, char str2) 
{
    char str[TAMSTR];
    strcpy(str, str1);
    strcat(str, str2);
    return str;
}


int main()
{
char vetor1[TAMSTR], vetor2[TAMSTR];
    strcpy(vetor1, "Joao");
    strcpy(vetor2, "Pedro");
    
    printf("%s", strcat(vetor1, vetor2));
    return 0;
}