/*
Ex.2 - Refaça o programa para calcular as raizes de uma equação do
segundo grau através da fórmula de Báscara, dando respostas
diferentes para os casos: delta menor que zero, igual ao zero
ou maior que zero.  
*/
#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, delta, x1, x2;
    printf("Calculo equação do segundo grau!\n");
    printf("a*x^2 + b*x + c = 0\n");
    printf("Entre com o valor a:");
    scanf ("%f", &a);
    printf("Entre com o valor b:");
    scanf ("%f", &b);
    printf("Entre com o valor c:");
    scanf ("%f", &c);
    delta = pow(b, 2) - 4*a*c;
    if (delta < 0)
    {
        printf("A equação não apresenta raizes reais");
    } else 
    {
        if (delta == 0) 
        {
            x1 = -b/2*a;
            printf("x1 = x2 = %.2f", x1);
        } else 
        {
            x1 = (-b+sqrt(delta))/2*a;
            x2 = (-b-sqrt(delta))/2*a;
            printf("x1 = %.2f", x1);
            printf("\nx2 = %.2f", x2);
        }
    }
    return 0;
}

