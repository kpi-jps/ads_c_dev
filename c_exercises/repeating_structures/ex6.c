/******************************************************************************

Ex. 6 Definir um programa que receba uma série de pares de
números, e para cada par calcule a média aritmética,
imprimindo o resultado. A série termina quando for lido o par
0,0.

*******************************************************************************/
#include <stdio.h>

int main()
{
    float x = 1, y = 1, med;
    while (x > 0 && y > 0) 
    {
        printf("Entre com o valor real para o x: ");
        scanf("%f", &x);
        printf("Entre com o valor real para o y: ");
        scanf("%f", &y);
        med = (x+y)/2;
        printf("A média aritmética entre x e y é: %.2f \n", med);
    }
    return 0;
}

