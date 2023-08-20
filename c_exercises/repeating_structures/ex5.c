/******************************************************************************
Ex.5 - Escrever um programa que calcula e escreve o produto dos
números primos entre 92 e 1478.
*******************************************************************************/
#include <stdio.h>

int main()
{
    int num = 2, i, prod = 1;
    printf("O produto entre os números primos que estão entre 92 e 1478 é: \n ");
        
        while (num <= 1478) 
        {
            i = 2;
            while (num % i != 0) 
            {
                i++;
            }
            if (num == i && num > 92 && num <=1478) 
            {
               prod *= num;
               printf("%i,", num);
            }
            num++;
        }
    printf("\n %i", prod);
    return 0;
}


