/******************************************************************************
Ex.1 - Escrever um programa que lê um conjunto de valores,
imprimindo, para cada valor: seu quadrado, seu cubo e sua raiz
quadrada. O conjunto é finalizado com o valor zero.

*******************************************************************************/
#include <stdio.h>
#include <math.h>

int main()
{

    float num = 1;
    while (num != 0) 
    {
        printf("Digite um valor real ou zero para finalizar: ");
        scanf("%f", &num);
        printf("Quadrado de %.2f = %.2f \n", num, pow(num,2));
        printf("Cubo de %.2f = %.2f \n", num, pow(num,3));
        printf("Raiz quadrada de %.2f = %.2f \n", num, sqrt(num));
    }
    return 0;
}






