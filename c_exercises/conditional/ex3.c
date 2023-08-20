/*
Ex.3 - Ler um número de 1 a 7 indicando o dia da semana.O programa
deve imprimir o dia em extenso e uma mensagem dizendo se é
dia útil ou final de semana. Por exemplo, se for digitado 1, o
programa imprime: Domingo - final de semana. Se for digitado
2, o programa imprime: Segunda - dia útil e assim por diante.  
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
    if (delta > 0)
    {
        printf("A equação não apresenta raizes reais");
    } else 
    {
        if (delta == 0) 
        {
            x1 = -b/2*a;
            printf("x1 = x2 = " "%.2f", x1);
        } else 
        {
            x1 = (-b+sqrt(delta))/2*a;
            x2 = (-b-sqrt(delta))/2*a;
            printf("x1 = " "%.2f", x1);
            printf("\nx2 = " "%.2f", x2);
        }
    }
    return 0;
}
