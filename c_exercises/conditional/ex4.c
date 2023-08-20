/*
Ex.4 - Escreva um programa que receba um número e responda se é
par ou impar. 
*/
#include <stdio.h>


int main()
{
    int num; 
    printf("Digite um número inteiro: ");
    scanf("%i", &num);
    if (num%2 == 0) 
    {
        printf("O número digitado é par!");
    } else 
    {
        printf("O número digitado é impar!");
    }
    return 0;
}

