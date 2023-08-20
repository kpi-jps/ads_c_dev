/******************************************************************************

Ex1- Elabore um programa para ler o nome e o sobrenome
de dez pessoas, imprimindo-os no seguinte formato:
sobrenome, nome.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
    char nome[50];
    char sobrenome[80];
    int i, j; //contadores
    
    for (i = 0; i < 10; i++) 
    {
        printf(" \n Entre com um nome %i :", i+1);
        gets(nome);
        printf("Entre com o sobrenome %i :", i+1);
        gets(sobrenome);
        printf("\n %s, %s", sobrenome, nome);
    }
    
    return 0;
}