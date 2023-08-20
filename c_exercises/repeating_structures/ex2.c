/******************************************************************************
Ex.2 - Escreva um programa que leia um número inteiro positivo e
mostre o seu fatorial.

*******************************************************************************/
#include <stdio.h>
#include <math.h>

int main()
{

    int num, i, fatorial = 1;
    printf("Entre com um número inteiro para o cálculo do fatorial: ");
    scanf("%i", &num);
    i = num;
    while (i > 0) 
    {
        fatorial *= i;
        i--;
    }
    printf("fatorial(%i) = %i\n", num, fatorial);
    return 0;
}

