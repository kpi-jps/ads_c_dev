/******************************************************************************

Ex.8 Chico tem 1,50 metro e cresce 2 centímetros por ano,
enquanto Zé tem 1,10 metro e cresce 3 centímetros por ano.
Construa um programa que calcule e imprima quantos anos
serão necessários para que Zé seja maior que Chico.

*******************************************************************************/
#include <stdio.h>

int main()
{
    float  altChico = 1.50, altZe = 1.10;
    int anos = 0;
    while (altZe < altChico) 
    {
        altChico += 0.02;
        altZe += 0.03;
        anos++;
    }
    printf("Serão necessários %i anos para que Zé fique maior que Chico", anos);
    return 0;
}


