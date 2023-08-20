/*
Faça um programa em C que receba 3 números inteiros
digitados pelo usuário e os mostre de forma ordenada na tela
*/
#include <stdio.h>


int main()
{
    int x, y, z; 
    printf("Digite um valor inteiro para x: ");
    scanf("%i", &x);
    printf("Digite um valor inteiro para y: ");
    scanf("%i", &y);
    printf("Digite um valor inteiro para z: ");
    scanf("%i", &z);
    if (x < y && y < z) 
    {
       printf("%i, %i, %i", x, y , z);
    } 
    else if (y < x && x < z)
    {
        printf("%i, %i, %i", y, x , z);
    } 
    else if (x < z && z < y) 
    {
        printf("%i, %i, %i", x, z , y);
    }
    else if (y < z && z < x)
    {
        printf("%i, %i, %i", y, z , x);
    }
    else if (z < x && x < y) 
    {
        printf("%i, %i, %i", z, x , y);
    } 
    else if (z < y && y < x)
    {
        printf("%i, %i, %i", z, y , x);
    }
    return 0;
}

