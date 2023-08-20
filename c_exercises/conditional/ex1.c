/*
Ex. 1 - Fazer um programa para ler um número e imprimir uma
mensagem informando se ele é positivo, negativo ou igual a
zero. 
*/
#include <stdio.h>

int main()
{
    float num;
    printf("Entre com o valor para um número real:");
    scanf ("%f", &num);
    if (num == 0)
    {
        printf("O número digitado é igual a 0!");
    } else 
    {
        if (num > 0) 
        {
            printf("O número digitado é maior que 0!");
        } else 
        {
            printf("O número digitado é menor que 0!");
        }
    }
    return 0;
}

